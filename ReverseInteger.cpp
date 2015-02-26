/**
 * Reverse digits of an interger.
 * Example: x=123, return 321
 * Example: x=-123, return -321
 * Did you notice that the reversed integer might overflow?
 * Assume the input is a 32-bit integer, then the reverse of 1000000003
 * overflows. How should you handle such cases?
 * For the purpose of this problem, assume that your function return 0
 * when the reversed integer overflows.
 */

class ReverseInteger {
public:
	int reverse(int x) {
		long ret = 0;
		while (x != 0) {
			ret = ret*10 + x%10;
			x = x/10;
		}
		if (ret > INT_MAX || -ret > INT_MAX)
			return 0;
		return ret;
	}
};
