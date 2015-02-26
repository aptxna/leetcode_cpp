/**
 * Given a string, determine if it is a palindrome, considering
 * only alphanumeric charactiers and ignoring cases.
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * we define empty string as valid palindrome.
 */

class ValidPalindrome {
public:
	bool isPalindrome(strings) {
		if (s.empty()) return true;
		int start=0, end=s.size()-1;
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		while (start<end) {
			while (start<end && !isAlpha(s[start])) start++;
			while (start<end && !isAlpha(s[end])) end--;
			if (s[start]!=s[end]) break;
			start++;
			end--;
		}
		if (start>=end)
			return true;
		else
			return false;
	}

	bool isAlpha(char c) {
		if (c>='a' && c<='z') return true;
		if (c>='0' && c<='9') return true;
		return false;
	}
};
