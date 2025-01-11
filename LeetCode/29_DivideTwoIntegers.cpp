#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if ((dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0))
        {
            return divCalc(divisor, dividend);
        }
        else
        {
            divisor = abs(divisor);
            dividend = abs(dividend);
            return (0 - divCalc(divisor, dividend));
        }
    }

    int divCalc(int divisor, int dividend)
    {
        if (dividend < divisor)
            return 0;
        int res = 1;
        int i = divisor;
        while (divisor + i < dividend)
        {
            divisor = divisor + i;
            res++;
        }
        return res;
    }
};
int main()
{
    Solution sol;
     cout << sol.divide(10, 3)<<endl;
     cout << sol.divide(10, -3)<<endl;
     cout << sol.divide(7, -3)<<endl;
    return 0;
}