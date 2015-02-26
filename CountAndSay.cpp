/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * Note: The sequence of integers will be represented as a string.
 */

#include <string>
#include <sstream>
using namespace std;

class CountAndSay {
public:
	string countAndSay(int n) {
		if (n<0) return "error input";
		if (n==0) return "";
		string s="1";
		for (int i=1; i<n; i++) {
			string temp = "";
			for (int j=0; j<s.length(); j++) {
				int count = 1;
				while (j+1<s.length() && s[j]==s[j+1]) {
					count++;
					j++;
				}
				stringstream ss;
				ss << count;
				temp += ss.str();
				temp += s[j];
			}
			s = temp;
		}
		return s;
	}
};
