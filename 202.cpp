class Solution {
public:
    bool isHappy(int n) {
        typedef map<int, bool> MapType;
        MapType m_int_bool;
        while(n != 1) {
            if (m_int_bool.find(n) == m_int_bool.end()) {
                m_int_bool[n] = 1;
            } else {
                return false;
            }
            int sum = 0;
            int temp = n;
            while (temp != 0) {
                sum += (temp % 10) * (temp % 10);
                temp = temp / 10;
            }
            
            n = sum;
        }
        return true;
    }
