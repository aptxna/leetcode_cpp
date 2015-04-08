/*
 * Wildcard Matching
 * 
 * Implement wildcard pattern matching with support for '?' and '*'.
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 * 
 * 参考： http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html
 * 
 */

class WildcardMatching {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star = NULL; //标记星号的位置
        const char* str = s; //标记s串的位置
        
        while (*s) {
            if (*p == *s || *p == '?') {
                s++;
                p++;
                continue;
            }
            if (*p == '*') {
                star = p;
                str = s;
                p++;
                continue;
            }
            if (star) {
                p = star + 1;
                s = ++str;
                continue;
            }
            return false;
        }
        
        while (*p == '*') p++;
        return (*p == '\0');
    }
};