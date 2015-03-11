/**
 * Single Number
 * 
 * Given an array of integers, envery element appears twice except for one.
 * Find that single number.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 * 
 * 思路：很简单，就是位操作，任意两个相同的数如果做异或(Exclusive Or)运算的话，结果为0。
 * 所以，这题的解法就是这么直白，从0开始到n，一路异或下去，最后剩下的值就是所求。
 */

class SingleNumber {
public:
    int singleNumber(int A[], int n) {
        int single = A[0];
        for (int i=1; i<n; i++) {
            single = single ^ A[i];
        }
        return single;
    }
};