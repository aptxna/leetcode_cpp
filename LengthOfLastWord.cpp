/**
 * Length of Last Word
 * Given a string s consists of upper/lower-case alphabets and
 * empty space characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0;
 * Note: A word is defined as a character sequence
 *       consistes of non-space characters only.
 *
 * For example,
 * Given s = "Hello World",
 * return 5.
 *
 * 求最后一个单词的长度，要考虑前后空格的情况
 * 分几种情况：
 * 1. " "
 * 2. " word"
 * 3. " word "
 * 4. "word "
 */

 class LengthOfLastWord {
 public:
 	int lenthOfLastWord(const char *s) {
 		int len = strlen(s);
 		if (len == 0)
 			return 0;
 		int i = len-1;
 		while (s[i] == ' ')
 			i--;
 		if (i == -1)
 			return 0;

 		int end = i;
 		for (; i>=0; i--) {
 			if (s[i] == ' ')
 				break;
 		}

 		if (i == -1)
 			return end+1;
 		else
 			return end-i;
 	}
 };