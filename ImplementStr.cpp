/**
 * Implement strStr()
 * Returns the index of the first occurrence of needle in haystack
 * or -1 if needle is not part of haystack.
 */

 /**
  * 一般匹配法
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