/**
 * Determine whether an integer is a palindrome.
 * Do this without extra space.
 */

class PalindromeNumber {
public:
	bool isPalidrome(int x) {
		int len=0, d=1;
		if (x<0) return false;
		if (x>=0 && x<10) return true;
		while (d<=x/10) {
			d *= 10;
		}
		while (x>0) {
			if (x/d != x%10)
				return false;
			x = (x%d)/10;
			d /= 100;
		}
		return true;
	}
};
