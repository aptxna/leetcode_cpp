/* 
 * Reverse Words in a String
 * 
 * Given an input string, reverse the string word by word.
 * 
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 */

class ReverseWordsInaString {
public:
    void reverseWords(string &s) {
        vector<string> ss;
        string tp;
        string result;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] != ' ' && i < s.size() - 1) {
                tp.push_back(s[i]);
            }
            
            if (s[i] != ' ' && i == s.size() - 1) {
                tp.push_back(s[i]);
                ss.push_back(tp);
            }
            
            if (s[i] == ' ') {
                if (s[i-1] != ' ' && i-1 >= 0) {
                    ss.push_back(tp);
                    tp.clear();
                }
                else
                    continue;
            }

        }
        
        reverse(ss.begin(), ss.end());
        
        for (int i=0; i<ss.size(); i++) {
            if (i != ss.size()-1) {
                result.append(ss[i] + ' ');
            }
            else
                result.append(ss[i]);
        }
        
        s = result;
    }
};


/* 
 * Following is another solution from: http://yucoding.blogspot.com/2014/03/leetcode-questions-reverse-words-in.html
 * 
 */

class Solution {
public:
    void reverseWords(string &s) {
        string word; //tmp string to store each word
        string res; // result string
        int i=0;
        while (i<s.size()){
        	// multiple spaces
            if (char(s[i])==' ' && word.empty()) {
            	i++;
            	continue;
            }

            // first space after a word
            if (char(s[i])==' ' && !word.empty()) {
                res = word+" "+ res; //store the word
                word=""; //reset the word
                i++;
                continue;
            }

            // non-space chars
            if (char(s[i])!=' ') {
            	word=word+char(s[i]);i++;
            	continue;
            }
        }
        
        // last word
        if (!word.empty()) {
            s = word+" "+res;
        }
        else {
            s = res;
        }
        
        s = s.substr(0,s.size()-1); //eliminate the last space
    }
};