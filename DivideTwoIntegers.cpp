/* 
 * Divide Two Integers
 * 
 * Divide two integers without using multiplication, division and mod operator.
 * If it is overflow, return MAX_INT.
 *
 * http://blog.csdn.net/majing19921103/article/details/44862875
 *
 */

class DivideTwoIntegers {
public:
    int divide(int dividend, int divisor) {
    	//这里不能用直接用abs(dividend)，考虑溢出
    	//INT_MIN = -2147483648 = -2^31
    	//INT_MAX = 2147483647 = 2^31 - 1
    	//abs(-2147483648) 还是 -2147483648
    	//所以先转成长整型再取绝对值
        //否则会在后面的循环中造成死循环
        //http://stackoverflow.com/questions/29526492/time-limit-exceeded-with-abs-in-a-c-program/29526933#29526933
        long long dvd = dividend, dvs = divisor;
        dvd = abs(dvd);
        dvs = abs(dvs);
        long long result = 0;
        
        while (dvd >= dvs) {
            long long temp = dvs;
            int i = 0;
            while (dvd >= temp) {
                temp = temp << 1; //左移一位乘以2
                i++;
            }

            //这里被除数已经大于除数了，所以需少乘一个2，也可以写成temp除以2
            // dvd -= temp >> 1
            dvd -= dvs << (i-1);
            result += (long long)1 << (i-1);
        }
        
        //正负符号判断
        result = ((long long)dividend > 0 ^ (long long)divisor > 0) ? -result : result;
        
        //判溢出：if it is overflow, return INT_MAX
        if (result > (1<<31) - 1)
            return (1<<31) - 1;
            
        return result;
    }
};