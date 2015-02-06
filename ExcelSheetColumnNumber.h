/**
 * Given a column title as appear in an Excel sheet, return its
 * corresponding column number.
 * For Example:
 * A->1
 * B->2
 * c->3
 * ...
 * Z->26
 * AA->27
 * AB->28
 * 思路：相当于26进制转10进制
 */

class ExcelSheetColumnNumber {
public:
	int titleToNumber(string s) {
		int num = 0;
		for (int i = 0; i < s.size(); i++) {
			num = num * 26 + (s[i] - 'A') + 1;
		}
		return num;
	}
};
