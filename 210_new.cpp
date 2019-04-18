class Solution {
public:
    //有向无环图 拓扑排序
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>{});
        for (auto item : prerequisites) {
            graph[item.first].push_back(item.second);
        }
        vector<int> trace(numCourses, -1); //记录一条路径下走过的节点，-1没走过，0走着，1走完了
        vector<int> res;
        for (int i = 0; i < graph.size(); i++) {
            if (!dfs(graph, i, trace, res)) {
                return vector<int> {};
            }
        }
        return res;
    }
    bool dfs(vector<vector<int>>& graph, int course, vector<int> &trace, vector<int> &res) {
        if (trace[course] == 1) { //走过了
            return true;
        }
        if (trace[course] == 0) { //有环
            return false;
        }
        trace[course] = 0;
        for (auto relyCourse : graph[course]) {
            if (!dfs(graph, relyCourse, trace, res)) {
                return false;
            }
        }
        trace[course] = 1;
        res.push_back(course); //拓扑排序按时间先后顺序加入结果链表
        return true;
    }
};
