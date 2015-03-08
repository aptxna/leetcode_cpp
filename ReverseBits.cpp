/**
 * Reverse Bits
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596(represented in binary as
 * 00000010100101000001111010011100),
 * return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up: If this function is called many times, how would you optimized it?
 *
 * 关于位运算的操作参考：
 * http://www.cnblogs.com/ktyanny/archive/2009/12/25/1632297.html
 */

 class ReverseBits {
 public:
 	uint32_t reverseBits(uint32_t n) {
 		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
 		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
 		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
 		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
 		n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);

 		return n;
 	}
 };