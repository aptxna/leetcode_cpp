/**
 * Given a positive integer, return its corresponding column title
 * as appear in an Excel sheet.
 * For example:
 * 1->A
 * 2->B
 * 3->C
 * ...
 * 26->Z
 * 27->AA
 * 28->AB
 * 思路：10进制转26进制，整型转字符型
 */

class ExcelSheetColumnTitle {
public:
	string converToTitle(int n) {
		if (n==0) return "";
		string s;
		stringstream s1;
		while (n>0) {
			s1 << char('A' + (n-1)%26);
			n = (n-1)/26;
		}
		s1 >> s;
		stringstream s2;
		for (int i=s.size()-1; i>=0; i--) {
			s2 << s[i];
		}
		s2 >> s;
		return s;
	}
};
