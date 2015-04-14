/**
 * Factorial Trailing Zeros
 * given an integer n, return the number of trailing zeroes in n!
 * Note: your solution should be in logarithmic time complexity.
 * 
 * 返回n的阶乘后缀0的个数！
 * 
 * 2×5=10，2比5多，数5就可以了！
 *
 */


 class FactorialTrailingZeroes {
 public:
 	int trailingZeroes(int n) {
 		int number = 0;
 		while (n>0) {
 			number += n/5;
 			n /= 5;
 		}
 		return number;
 	}
 }