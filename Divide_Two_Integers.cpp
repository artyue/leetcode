class Solution {
public:
    int divideImp(unsigned long long dividend, unsigned long long divisor) {
        if (dividend < divisor)
            return 0;
        if (dividend == divisor)
            return 1;
        if (divisor == 1)
            return (int)dividend;
        
        long long cur_divend = dividend, res = 0;
        while (cur_divend > 0) {
            unsigned long long pow2 = 0, cur_divisor = divisor;
            while (cur_divend >= cur_divisor) {
                cur_divisor = cur_divisor << 1;
                if (pow2 == 0)
                    ++pow2;
                else
                    pow2 = pow2 << 1;
            }
            res += pow2;
            cur_divend -= (cur_divisor >> 1);
        }
        return (int)res;
    }
    
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        if (dividend == divisor)
            return 1;
        if (divisor == 1)
            return dividend;
        
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            return -divideImp(abs((long long)dividend), abs((long long)divisor));
        return divideImp(abs((long long)dividend), abs((long long)divisor));
    }
};
