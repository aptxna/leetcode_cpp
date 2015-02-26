/**
 * Write a function to find the longest common prefix string amongst
 * an array of strings.
 */

class LCP {
public:
	string longestCommonPrefix(vector<string> &strs) {
		int n = strs.size();
		if (n==0) return "";
		int len = strs[0].size();
		for (int i=1; i<strs.size(); i++) {
			int j;
			for (j=0; j<min(len, (int)strs[i].size()); j++) {
					if (strs[0][j] != strs[i][j])
						break;
			}
			len = j;
		}
		return strs[0].substr(0, len);
	}
};
