/**
 * Word Ladder II
 * 
 * Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * Return
 * [
 *   ["hit","hot","dot","dog","cog"],
 *   ["hit","hot","lot","log","cog"]
 * ]
 * 
 * Note:
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * 
 * 太难了。。。无语凝噎
 * 参考：
 * http://yucoding.blogspot.com/2014/01/leetcode-question-word-ladder-ii.html
 */

class WordLadderII {
private:
    vector<vector<string>> result; //用来存所有可能的路径
    vector<string> ladder; //用来存一条路径
    unordered_map<string, vector<string>> tracemap; //记录回溯
    unordered_set<string> currentLevel;
    unordered_set<string> nextLevel;
    
    //改变单词中一个字母，如果结果在字典中，则把改变后的单词push到下一个level，并记录在map中方便回溯
    void transWord(string str, unordered_set<string> &dict, unordered_set<string> &nextLevel) {
        for (int i=0; i<str.size(); i++) {
            string trans = str;
            for (int j='a'; j<='z'; j++) {
                trans[i] = j;
                //如果这个单词在字典中
                if (dict.find(trans) != dict.end()) {
                    //unordered_set::insert() ignores the duplicated key, just keep one
                    //that's why we use unordere_sert not queue or other
                    //because unordered_set stores the unique key
                    nextLevel.insert(trans);
                    //将变更后的单词作为tracemap的key，对应的变换前的单词push到作为value的vector中
                    //注意：trans在nextLevel，str在currentLevel
                    //回溯找路径的时候，从最终结果开始向上直到start，每一个单词的上一个结点就在map的vector中
                    tracemap[trans].push_back(str);
                }
            }
        }
    }
    
    //回溯路径，并输出
    void getPath(string &start, string previousword) {
        //如果上一个结点为初始结点则输出结果
        if (previousword == start) {
            reverse(ladder.begin(), ladder.end());
            result.push_back(ladder);
            reverse(ladder.begin(), ladder.end());
        }
        else {
            for (int i=0; i<tracemap[previousword].size(); i++) {
                //把当前结点的上一个结点push到路径中来
                //注意：previousword是当前结点，tracemap[previousword][i]是上一个结点
                ladder.push_back(tracemap[previousword][i]);
                getPath(start, tracemap[previousword][i]); //递归调用找上一个结点
                ladder.pop_back();
            }
        }
    }
    
    void initial(unordered_set<string> &dict, string &start, string &end) {
        result.clear();
        ladder.clear();
        tracemap.clear();
        
        dict.insert(start);
        dict.insert(end);
        
        ladder.push_back(end);
        currentLevel.insert(start);
    }
    
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        initial(dict, start, end);
        
        while(!currentLevel.empty()) {
            for (auto iterator=currentLevel.begin(); iterator!=currentLevel.end(); iterator++) {
                dict.erase(*iterator);
            }
            for (auto iterator=currentLevel.begin(); iterator!=currentLevel.end(); iterator++) {
                transWord(*iterator, dict, nextLevel);
            }
            if (nextLevel.find(end) != dict.end()) {
                getPath(start, end);
                return result;
            }
            
            currentLevel.clear();
            currentLevel = nextLevel;
            nextLevel.clear();
        }
        
        return result;
    }
};