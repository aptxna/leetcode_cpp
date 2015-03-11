/**
 * Number of 1 Bits
 * 
 * Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */

class NumberOf1Bits {
public:
    int hammingWeight(uint32_t n) {
        int one = 1;
        int count = 0;
        while (n > 0) {
            count = count + (one & n);
            n = n >> 1;
        }
        
        return count;
    }
};