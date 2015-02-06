/**
 * Given a string containing just the characters '(', ')', '{', '}', '[', ']',
 * determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid
 * but "(]" and "([)]" are not.
 * 思路：遍历字符串里的每个字符，如果不是右边括号则入栈，如果是则先判栈是否为空，
 * 若栈为空则返回false，否则将该符号和栈顶符号相比较：
 * 若匹配则删除栈顶符号，同时字符串下标移向后一位符号，若不匹配则返回false。
 * 遍历结束，若栈为空则返回true，否则返回false。
 */

class ValidParentheses {
public:
	bool isValid(string s) {
		stack<char> st;
		int i=0;
		while(i!=s.size()) {
			char c=s[i];
			if (c!=')' && c!=']' && c!='}') {
				st.push(c);
			}
			else {
				if (st.empty())
					return false;
				char temp=st.top();
				switch(c) {
					case ')':
						if (temp=='(')
							st.pop();
						else
							return false;
						break;
					case ']':
						if (temp=='[')
							st.pop();
						else
							return false;
						break;
					case '}':
						if (temp=='{')
							st.pop();
						else
							return false;
						break;
				}
			}
			i++;
		}
		if (st.empty())
			return true;
		else return false;
	}
};
