#include<vector>
#include<iostream>
#include<stack>
#include<string>
//#include<unordered_set>
#include<climits>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        //int res;
        for (auto s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") { //是数字
                st.push(stoi(s));
            } else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if (s == "+") {
                    st.push(num1 + num2);
                } else if (s == "-") {
                    st.push(num1 - num2);
                } else if (s == "*") {
                    st.push(num1 * num2);
                } else if (s == "/") {
                    st.push((int)(num1 / num2));
                }
            }
        }
        return st.top();
    }
};
int main() {
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << (new Solution)->evalRPN(tokens) << endl;
}
