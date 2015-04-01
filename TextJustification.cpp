/**
 * Text Justification
 * 
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
 * Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 * Extra spaces between words should be distributed as evenly as possible.
 * If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 * Return the formatted lines as:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 * Note: Each word is guaranteed not to exceed L in length.
 * 
 * Corner Cases:
 * A line other than the last line might contain only one word. What should you do in this case?
 * In this case, that line should be left-justified.
 */


class TextJustification {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        int i=0;
        while(i < words.size()) {
            int singleline = words[i].size();
            int j=i+1;
            while (j<words.size() && singleline + words[j].size() < L) {
                singleline += 1 + words[j++].size(); //单词之间至少间隔一个空格符
            }
            
            //结尾，最后一行的时候，左对齐，如有需要，右边补充空格
            if (j == words.size()) {
                string s = words[i];
                while (i+1 < j) {
                    s.append(' ' + words[++i]);
                }
                if (s.size() < L) {
                    s.append(L-s.size(), ' ');
                }
                result.push_back(s);
                return result;
            }
            
            //处理一行只有一个单词的情况
            else if (j-i == 1) {
                result.push_back(words[i].append(L-words[i].size(), ' '));
                i++; //这里i不要忘了自增1
                continue; //回到循环起始条件判断处继续
            }
            
            //处理一般情况，空格均匀分布
            //平均每个间隔分布的空格，因为单词之间至少间隔一个空格，所以还要加1
            else {
                int slot = (L - singleline) / (j - i - 1) + 1;
                int remainder = (L - singleline) % (j - i - 1);
                string s = words[i];
                while (i+1 < j) {
                    s.append(slot, ' ');
                    if (remainder > 0) {
                        s.push_back(' '); //可以用string::push_back(char c)或者string::append(size_t n, char c)
                        remainder--;
                    }
                    s.append(words[++i]);
                }
                result.push_back(s);
                i++; //这里i不要忘了自增1
            }
        }
        return result;
    }
};