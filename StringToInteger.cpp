/**
 * Implement atoi to convert a string to an integer.
 * 溢出判断坑死我了
 */

class StringToInteger {
public:
	int atoi(string str) {
		int res=0, sign=1, i=0;
		while (str[i]==' ') {
			i++;
		}
		if (str[i]=='-' || str[i]=='+') {
			sign = 1 - 2*(str[i++]=='-');
		}

		while (str[i]>='0' && str[i]<='9') {
			if (res > INT_MAX/10 || (res == INT_MAX/10 && str[i]-'0' > 7)) {
				if (sign==1)
					return INT_MAX;
				else
					return INT_MIN;
			}
			res = res*10 + (str[i++]-'0');
		}

		return res*sign;
	}
};
