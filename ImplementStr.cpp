/**
 * Implement strStr()
 * Returns the index of the first occurrence of needle in haystack
 * or -1 if needle is not part of haystack.
 */

/**
 * 一般匹配法
 * m为字符串长度
 * n为模式串长度
 * 算法复杂度O(m*n)
 */

class ImplementStrSol1 {
public:
  	int strStr(char *haystack, char *needle) {
  		if (haystack == NULL || needle == NULL)
  			return -1;
  		int hlen = strlen(haystack);
  		int nlen = strlen(needle);
  		if (hlen < nlen)
  			return -1;

  		for (int i=0; i<hlen-nlen+1; i++) {
  			int p = i;
  			int j;
  			for (j=0; j<nlen; j++) {
  				if (haystack[p] != needle[j])
  					break;
  				p++;
  			}

  			if (j == nlen)
  				return i;
  		}

  		return -1;
  	}
  };

/**
 * KMP算法
 * m为字符串长度
 * n为模式串长度
 * 算法复杂度为O(m+n)
 * 代码基于July的这篇blog
 * http://blog.csdn.net/v_july_v/article/details/7041827
 */

class ImplementStrSol2 {
public:
    int strStr(char *haystack, char *needle) {
        int hlen = strlen(haystack);
        int nlen = strlen(needle);
        int next[100000];
        
        generatePatternNextArray(needle, next);
        kmpSearch(haystack, needle, next);
    }
    
    //next[]数组表示模式串（needle）中当前不匹配字符前已匹配字符串相同前缀后缀的最大长度
    //generatePatternNextArray用来生成模式串的next[]数组
    void generatePatternNextArray(char *p, int next[]) {
        int plen = strlen(p);
        next[0] = -1;
        int k = -1;
        int j = 0;
        
        while (j < plen - 1) {
            //p[k]表示前缀，p[j]表示后缀
            if (k == -1 || p[j] == p[k]) {
                k++;
                j++;
                
                //如果p[j]等于p[next[j]]
                //那么当p[j]不匹配时，p[next[j]]也不会匹配
                //因此继续递归k=next[k]=next[next[k]]
                if (p[j] != p[k])
                    next[j] = k;
                else
                    next[j] = next[k];
            }
            else {
                //如果p[k]和p[j]失配
                //则用p[next[k]]和p[j]比较
                //如果p[next[k]]跟p[j]还是不匹配，则下一步用p[next[next[k]]]去跟p[j]匹配
                //相当于模式串的自我匹配
                //所以不断地递归k=next[k]
                //直到要么找到长度更小的相同前缀后缀，要么没有长度更小的相同前缀后缀。
                k = next[k];
            }
        }
    }
    
    //kmpSearch用KMP算法搜索被匹配字符串中模式串第一次出现的位置
    int kmpSearch(char *str, char *p, int next[]) {
        int slen = strlen(str);
        int plen = strlen(p);
        int i = 0;
        int j = 0;
        
        while (i < slen && j < plen) {
            if (str[i] == p[j] || j == -1) {
                i++;
                j++;
            }
            else {
                j = next[j];
            }
        }
        
        if (j == plen)
            return i - j;
        else
            return -1;
    }
};