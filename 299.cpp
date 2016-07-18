//用两个可重复元素的hashset保存除bulls以外的元素
//stringstream可将任何类型的变量转换为string型
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_multiset<char> ms_char_s;
        unordered_multiset<char> ms_char_g;
        int a = 0, b = 0;
        
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] == secret[i]) {
                a++;
            } else {
                ms_char_s.insert(secret[i]);
                ms_char_g.insert(guess[i]);
            }
        }
        
        for (auto it = ms_char_g.begin(); it != ms_char_g.end(); ++it) {
            auto secret_ele = ms_char_s.find(*it);
            if (secret_ele != ms_char_s.end()) {
                ms_char_s.erase(secret_ele);
                b++;
            }
        }
        
        //stringstream st1;//将int转换为string，使用stringstream完成
        //stringstream st2;
        //string temp1;
        ///string temp2;
        //st1 << a;
        //st1 >> temp1;
        //st2 << b;
        //st2 >> temp2;
        
        
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};
