//第二个'#'从来不入栈
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> s_char;
        for (int i = 0; i < preorder.size(); i++) { //因为一个有效的数字可能占两个，如92，不能用i += 2
            if (preorder[0] == '#' && preorder.size() != 1) {
                return false;
            }
        //    if (preorder[i] == ',') {//没必要这一步，因为31行
         //       continue;
        //    }
            
            if (preorder[i] == '#' && !s_char.empty()　//一定要先判断是否为空，不然top()会出现段错误
                    && s_char.top() == '#') {
                int j = 2;//出栈两次
                while (j--) {
                    if (s_char.empty()) {
                        return false;
                    } else {
                        s_char.pop();
                    }
                }
         //       s_char.push('#');
                i--;//画个图就能理解,继续用当前‘＃’循环
            } else {
                s_char.push(preorder[i]);
                
                while (preorder[i] != ',' && i != preorder.size() - 1) {
                    i++;
                }
            }
        }
        if (s_char.size() == 1 && s_char.top() == '#') {
             return true;
        } else {
            return false;
        }
    }


};
