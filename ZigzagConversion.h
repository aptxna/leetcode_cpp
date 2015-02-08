/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on
 * a given number of rows like this:(you may want to display this pattern
 * in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given
 * a number of rows:
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

class ZigzagConversion {
public:
	string convert(string s, int nRows) {
		if (nRows<=1) return s;
		string zs;
		int zigsize=2*nRows-2;
		for (int i=0; i<nRows; i++) {
			for (int j=i; ; j+=zigsize) {
				if (j>=s.size())
					break;
				zs.append(1, s[j]);
				if (i>0 && i<nRows-1) {
					int mid=j+zigsize-2*i;
					if (mid<s.size()) {
						zs.append(1, s[mid]);
					}
				}
			}
		}
		return zs;
	}
};
