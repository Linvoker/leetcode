class Solution {
public:
    string countAndSay(int n) {
        string temp = "1";
        while (--n) {
            temp = func(temp);
        }
        return temp;
    }
    string func(string &temp) {
        string ret_str;
        char comp = temp[0];
        int count = 1;
        for (int i = 1; i < temp.size(); i++) {
            if (comp == temp[i]) {
                count++;
            } else {
                ret_str.push_back('0' + count);
                ret_str.push_back(comp);
                comp = temp[i];
                count = 1;
            }
        }
        ret_str.push_back('0' + count);
        ret_str.push_back(comp);
        
        return ret_str;
    }
};
