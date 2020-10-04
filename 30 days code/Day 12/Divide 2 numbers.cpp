/*
  Description : Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
                Return the quotient after dividing dividend by divisor.
                The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
  Example 1:
                Input: dividend = 10, divisor = 3
                Output: 3
                Explanation: 10/3 = truncate(3.33333..) = 3.
  Example 2:
                Input: dividend = 7, divisor = -3
                Output: -2
                Explanation: 7/-3 = truncate(-2.33333..) = -2.
  Note:
                Both dividend and divisor will be 32-bit signed integers. The divisor will never be 0.
                Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
                For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

// 1st approach is keep dividing divisor from dividend untill dividend>=divisor. this will take O(dividend). Another is using bit approach here it is O(log(dividend)).
// Code
  int divide(long long dividend, long long divisor) {
        long long q = 0, t = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1  : 1;
        dividend = abs(dividend); 
        divisor = abs(divisor); 
        for(long long i = 31; i>-1; i--){
            if(t + (divisor<<i) <= dividend){
                t += divisor<<i;
                q |= 1LL<<i;
            }
        }
        q *= sign;
        return q>=INT_MAX || q<INT_MIN ? INT_MAX:q;
    }
