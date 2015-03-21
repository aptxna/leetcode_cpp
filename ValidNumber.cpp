/**
 * Valid Number
 * Validate if a given string is numeric.
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 * 
 * 参考：
 * http://blog.csdn.net/kenden23/article/details/18696083
 * http://jelices.blogspot.com/2013/12/leetcode-valid-number.html
 */

class ValidNumber {
private:
    int getChar(char c) {
        if (c == ' ') return 1;  
        else if (c == '+' || c == '-') return 2;  
        else if (isdigit(c)) return 3;  
        else if (c == '.') return 4;  
        else if (c == 'e' || c == 'E') return 5;
        else return 0;
    }
    
    int getNextState(int state, char c) {
        int transTable[][6] = {
        //0:invalid, 1:space, 2:symbol, 3:digit, 4:dot, 5:exponent 
	          -1,       0,        3,       1,      2,       -1,    // 0: 初始无输入或者只有space的状态  
	          -1,       8,       -1,       1,      4,        5,    // 1: 输入了数字之后的状态  
	          -1,      -1,       -1,       4,     -1,       -1,    // 2: 前面无数字，只输入了dot的状态  
	          -1,      -1,       -1,       1,      2,       -1,    // 3: 输入了symbol的状态  
	          -1,       8,       -1,       4,     -1,        5,    // 4: 前面有数字和有dot的状态  
	          -1,      -1,        6,       7,     -1,       -1,    // 5: 'e' or 'E'输入后的状态  
	          -1,      -1,       -1,       7,     -1,       -1,    // 6: 输入e之后输入symbol的状态  
	          -1,       8,       -1,       7,     -1,       -1,    // 7: 输入e后输入数字的状态  
	          -1,       8,       -1,      -1,     -1,       -1,    // 8: 前面有有效数输入之后，输入space的状态 
        };
        return state = transTable[state][getChar(c)];
    }
    
public:
    bool isNumber(string s) {
        int state = 0;
        for (int i=0; i<s.length(); i++) {
            state = getNextState(state, s.at(i));
            if (state == -1)
                return false;
        }
        
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};