/**
 * Plus One
 *
 * Given a non-negative number represented as an array of digits,
 * plus one to the number.
 * The digits are stored such that the most significant digit
 * is at the head of the list.
 *
 * 模拟加法进位
 */

 class PlusOne {
 public:
 	vector<int> plusOne(vector<int> &digits) {
 		int carry = 1;
 		int sum = 0;
 		vector<int> result (digits.size(), 0);

 		for (int i=digits.size(); i>=0; i--) {
 			sum = digits[i] + carry;
 			carry = sum / 10;
 			result[i] = sum % 10;
 		}

 		if (carry > 0)
 			result.insert(result.begin(), carry);

 		return result.
 	}
 };