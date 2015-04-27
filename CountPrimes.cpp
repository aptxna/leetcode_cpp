/*
 * Count Primes
 * 
 * Description:
 * Count the number of prime numbers less than a non-negative number, n
 * 
 * Hint: The number n could be in the order of 100,000 to 5,000,000.
 * 
 * References:
 * Sieve of Eratosthenes
 *
 */

class CountPrimes {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        //数组定义在函数内部，属局部变量
        //局部变量存放在栈上，一个超百万数组占用内存过大会导致栈内存溢出
        //解决方法一：申明为全局变量，此处不可行
        //解决方法二：存放在堆上
        bool* prime = new bool[n];
        int count = 0;
        
        for (int i=2; i<n; i++) {
            prime[i] = true;
        }
        
        //去掉质数的平方数及其倍数
        for (int i=2; i<sqrt(n); i++) {
            if (prime[i]) {
                for (int j=i*i; j<n; j+=i) {
                    prime[j] = false;
                }
            }
        }
        
        //数组中值为真的个数即为n以内质数个数
        for (int i=2; i<n; i++) {
            count += prime[i] ? 1 : 0;
        }
        
        return count;
    }
};