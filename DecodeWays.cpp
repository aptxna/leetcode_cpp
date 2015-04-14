/*
 * Decode Ways
 * 
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 * 
 * For example,
 * 
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 * 
 * The number of ways decoding "12" is 2.
 * 
 */


class DecodeWays {
public:
    bool valid(string s) {
        if (s.size() == 0) return false;
        if (s[0] == '0') return false;
        if (s.size() == 2) {
            if (s[0] > '2' || (s[0] == '2' && s[1] > '6'))
                return false;
        }
        return true;
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> result(s.size(), 0);
        if (s[0] != '0') result[0] = 1; //如果第一个字符有效
        if (s.size() == 1) return result[0]; //如果只有一个字符
        if (valid(s.substr(0,2))) result[1]++; //如果头两个字符表示的数在1-26范围内
        if (s[0] != '0' && s[1] != '0') result[1]++; //如果头两个字符分别有效
        
        //这里开始动态规划
        for (int i=2; i<s.size(); i++) {
            if (s[i] != '0') result[i] += result[i-1];
            if (valid(s.substr(i-1, 2))) result[i] += result[i-2];
        }
        
        return result[s.size()-1];
    }
};