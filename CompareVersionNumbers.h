/*
 * Compare two version numbers version1 and version2.
 * if version1 > version2 return 1, if version1 < version2 return -1
 * otherwise return 0.
 * You may assume that the version strings are non-empty
 * and contain only digits and the . character.
 * The . character does not represent a decimal point and is used
 * to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three",
 * it is the fifth second-level revision of the second first-level revision.
 * Here is an example of vrsion numbers ordering:
 * 0.1 < 1.1 < 1.2 < 13.37
 */

#include <string>

class CompareVersionNumbers {
public:
	int compareVersion(string version1, string version2) {
		int res = 0;
		char* v1 = (char*) version1.c_str();
		char* v2 = (char*) version2.c_str();

		while (res == 0 && (*v1 != '\0' || *v2 != '\0')) {
			long intv1 = *v1 == '\0' ? 0 : strtol(v1, &v1, 10);
			long intv2 = *v2 == '\0' ? 0 : strtol(v2, &v2, 10);
			if (intv1 > intv2)
				res = 1;
			else if (intv1 < intv2)
				res = -1;
			else {
				if (*v1 != '\0') v1++;
				if (*v2 != '\0') v2++;
			}
		}

		return res;
	}
};


/*
 * another way to solve this problem
 */

class CompareVersionNumbers {
public:
	int compareVersion(string version1, string version2) {
		int i = 0, j = 0;
		int num1 = 0, num2 = 0;
		while (i < version1.size() || j < version2.size()) {
			num1 = 0, num2 = 0;
			while (i < version1.size() && version1[i] != '.') {
				//string to int
				//num1*10 is to move digit to left
				//in ASCII code, '0' is 48
				//minus '0' then trans char to int in decimal
				num1 = num1 * 10 + version[i] - '0';
				i++;
			}
			while (j < version2.size() && version2[j] != '.') {
				num2 = num2 * 10 + version[j] - '0';
				j++;
			}
			if (num1 > num2) return 1;
			else if (num1 < num2) return -1;
			else {
				i++;
				j++;
			}
		}
		return 0;
	}
};
