/**
 * Add Binary
 * 
 * Given two binary strings, return their sum (also a binary string).
 * 
 * For example,
 * a = "11"
 * b = "1"
 * return "100"
 * 
 * 先要将字符串转整型进行加法进位运算， 然后将数字转字符存入string
 */

 class AddBinary {
 public:
 	string addBinary(string a, string b) {
 		int carry = 0;
 		int digit = 0;
 		string result;

 		for (int i=a.size()-1, j=b.size()-1; i>=0 || j>=0; i--, j--) {
 			int ai = i>=0 ? a[i]-'0' : 0;
 			int bj = j>=0 ? b[j]-'0' : 0;

 			digit = (ai + bj + carry) % 2;
 			result.insert(result.begin(), digit+'0');
 			carry = (ai + bj + carry) / 2;
 		}

 		if (carry == 1)
 			result.insert(result.begin(), '1');

 		return result;
 	}
 };