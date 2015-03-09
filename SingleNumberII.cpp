/**
 * Single Number II
 * Given an array of integers, every element appears three times except for one.
 * Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 * 参考：
 * http://fisherlei.blogspot.com/2013/11/leetcode-single-number-ii-solution.html
 */

class SingleNumberII {
public:
    int singleNumber(int A[], int n) {
    	//这个vector用来按位存储每个数每一位的“1”个数
        vector<int> bit(32,0);
        //single用来返回最后的结果
        int single = 0;

        for (int i=0; i<n; i++) {
        	//singlebit用来和rotate之后的每个数进行与运算，以取得每一位的“1”
            int singlebit = 1;
            for (int j=0; j<32; j++) {
                int rotate = A[i] >> j;
                if (rotate == 0) break;
                //按位累加这些数
                bit[j] += rotate & singlebit;
            }
        }
        
        for (int i=0; i<32; i++) {
        	//对32位的每一位进行模3运算并累加
            single = single + (bit[i]%3 << i);
        }
        
        return single;
    }
};


/**
 * 优化之后的算法
 */

class SingleNumberII {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                count += ((A[j] >> i) & 1); //统计每一位的个数
            }
            result |= ((count % 3) << i);   //取余放回result
        }
        
        return result;
    }
};