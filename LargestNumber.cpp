/*
 * Largest Number
 * 
 * Given a list of non negative integers, arrange them such that they form the largest number.
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * 
 * Note: The result may be very large, so you need to return a string instead of an integer.
 */


class LargestNumber {
public:
    string largestNumber(vector<int> &num) {
        vector<string> str;
        string result;
        
        //将数字转字符串输入字符串vector中
        for (int i=0; i<num.size(); i++) {
            str.push_back(to_string(num[i]));
        }
        
        //用自定义比较函数将字符串由大到小排序
        sort(str.begin(), str.end(), compare);
        
        //排除特殊情况，多个0情况下只输出一个0
        if (str[0] == "0") return "0";
        
        //连接vector中的字符串输出到结果
        for (int i=0; i<str.size(); i++) {
            result += str[i];
        }
        
        return result;
    }
    
private:
    static bool compare(string &s1, string &s2) {
            return s1 + s2 > s2 + s1;
        }
};