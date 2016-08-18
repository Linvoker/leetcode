//转换成整数是不可行的,因为test case里的a和b会大于64位
//只好直接在较长的那个string上直接替换
//如果另外创建一个string给返回值,则不需要helper,也不用事先比较a和b的长度了
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() >= b.size()) {
            return helper(a, b);
        } else {
            return helper(b, a);
        }
        
    }
    string &helper(string &a, string &b) {
        int mark = 0;//进位
        for (int i = 0; i < a.size(); i++) {
            //特别注意这里要很小心,+号后面的最外括弧, (int)强制类型转换,-'0'获得整数.这些都是必须的
            char temp = a[a.size() - 1 - i] + (((int)b.size() - 1 - i < 0) ? 0 : (b[b.size() - 1 - i] - '0'));
            if (temp + mark >= '2') {//说明需要进位
                a[a.size() - 1 - i] = (temp + mark - '0') % 2 + '0';//这里也很需要注意
                mark = 1;
            } else {
                a[a.size() - 1 - i] = (temp + mark) ;//
                mark = 0;
            }
        }
        if (mark == 1) {//如果最后还需要进位
            a.insert(a.begin(), '1');
        }
        return a;
    }
};
