//注意candidates[]（nums[]）的变化情况，和combination系列的用begin加上去不一样。
//nums[]应该不用先排序，怎么样都行

//自己的16ms
//candidates不使用引用的方法了，通过copy传递给函数，因为一层里（递归调用）不同parent结点下的candidates都不同
//切掉candidates里使用过的元素：swap(使用过的，end()),再pop_back()就行了。
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret_vec;
        vector<int> trace;
        backTracing(ret_vec, trace, nums);
        return ret_vec;
    }
    void backTracing(vector<vector<int>> &ret_vec, vector<int> &trace, vector<int> candidates) {
        if (candidates.empty()) {
            ret_vec.push_back(trace);
            return ;
        }   
        for (int i = 0; i <= candidates.size() - 1; i++) {
            //没有剪枝函数，每个都要遍历
            trace.push_back(candidates[i]);
            
            vector<int> temp = candidates;
            swap(temp[i], temp[temp.size() - 1]);
            //temp.resize(candidates.size() - 1);
            temp.pop_back();
            backTracing(ret_vec, trace, temp);
            
            trace.pop_back();
        }
    }
    
};
//比人12ms的方法
//candidates和combinations系列问题一样用引用传递，再额外传递一个begin标示索引进行到哪个位置
//每次传递candidates（num）时，都swap（begin，当前位置），再将begin+1传递给递归的begin即可
/*class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};
