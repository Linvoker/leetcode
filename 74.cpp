//先找到行再找到列或许是个办法
/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m_end = matrix.size() - 1;
        int n_end = matrix[0].size() - 1;
        int m_begin = 0;
        while (m_end >= m_begin) {//根据lower_bound()的方法找到>=target的第一行
            int m_mid = m_end + (m_begin - m_end) / 2;//(m_begin + m_end) / 2
            
            if (matrix[m_mid][n_end] >= target) {//别用matrix[m_mid][0],因为这个循环是要找到 该值>=target的第一行，这一行一定要存在target的值
                m_end = m_mid - 1;
            } else {
                m_begin = m_mid + 1;
            }
        }
        if (m_begin > matrix.size() - 1) {//这一行很特么重要，因为上面的wihle()循环效果和lower_bound()一模一样，而lower_bound()没有找到
        //>=target的值时，返回类似end()的位置,这个位置并不存在，也就是下一行。
            return false;
        }
        if (matrix[m_begin][n_end] == target) {
            return true;
        } else {
            auto it = lower_bound(matrix[m_begin].begin(), matrix[m_begin].end(), target);
            if (*it == target) {
                return true;
            } else {
                return false;
            }
            
        }
        
    }
};*/
//将二维向量想象成一个一维向量
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() ;
        int n = matrix[0].size();
        int begin = 0;
        int end = m * n - 1;
        while (begin <= end) {
            int mid = end + (begin - end) / 2;
            
            if (matrix[mid / n][mid % n] >= target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        if (begin > m * n - 1) {//这一行很特么重要，因为上面的wihle()循环效果和lower_bound()一模一样，而lower_bound()没有找到
        //>=target的值时，返回类似end()的位置,这个位置并不存在，也就是下一行。
            return false;
        }
        return matrix[begin / n][begin % n] == target;
    }
};



