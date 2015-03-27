/**
 * Fraction to Recurring Decimal
 * 
 * Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 * For example,
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 */

class FractionToRecurringDecimal {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string outstr;
        
        //int64_t为8字节长整型，为防止后面分子分母取绝对值后溢出，因为INT_MIN取绝对值仍然是负数
        int64_t n = numerator, d = denominator;
        
        //对正负号进行处理，如果有负号，则负号先入
        if (n<0 ^ d<0)
            outstr += '-';
            
        n = abs(n), d = abs(d);
        
        //先取整数部分
        outstr += to_string(n/d); //std::to_string，将数值型转为string
        n %= d;
        
        //如果余数不为0，则加入小数点
        if (n)
            outstr += '.';

        //定义一个hash map，第一个int表示的key为小数，第二个int表示该小数在整个字符串中的位置
        unordered_map<int, int> decimal;

        //当余数不为0时
        while(n) {
        	//如果map中没有该小数
            if (decimal.find(n) == decimal.end()) {
                decimal[n] = outstr.size(); //记录小数位置
                n *= 10;
                outstr += to_string(n/d);
                n %= d;
            }
            else {
            	//如果map中出现重复key，说明该小数为循环位
                outstr.insert(decimal[n], 1, '(');
                outstr += ')';
                return outstr;
            }
        }
        return outstr;
    }
};