/* 
 * Word Break II
 * 
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 * Return all such possible sentences.
 * 
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 * A solution is ["cats and dog", "cat sand dog"].
 */

class WordBreakII {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<bool>> mp(s.size(), vector<bool>(s.size(), false));

        //该循环判断给定字符串的下标从i到j的子串能否在字典中找到，如果能则标记为true
        for (int i=0; i<s.size(); i++) {
            for (int j=i; j<s.size(); j++) {
                if (dict.find(s.substr(i, j-i+1)) != dict.end()) {
                    mp[i][j] = true;
                }
            }
        }
        
        bool wordBreak = false;
        vector<string> result;
        vector<int> pos;

        //这个循环判断该字符串能否被break
        for (int i=0; i<s.size(); i++) {
            if (mp[i][s.size()-1]) {
                wordBreak = true;
                break;
            }
        }
        
        //如果不能被break，返回result
        if (!wordBreak) return result;

        //如果能被break，进入depth first search
        dfs(s, 0, pos, result, dict, mp);

        //返回最终结果
        return result;
    }
    
    void dfs(string &s, int pre, vector<int> &pos, vector<string> &result, unordered_set<string> &dict, vector<vector<bool>> &mp) {
        if (pre >= s.size()) {
            string str = s;
            for (int i=0; i<pos.size()-1; i++) {
            	//注意这里为什么是pos[i]+i，因为增加空格后字符串长度也在改变，所以要加i。。。囧
                str.insert(pos[i]+i, " ");
            }
            result.push_back(str);
        }
        else {
            for (int j=0; j<s.size(); j++) {
                if (mp[pre][j] == true) {
                    pos.push_back(j+1);
                    dfs(s, j+1, pos, result, dict, mp);
                    pos.pop_back();
                }
            }
        }
    }
};