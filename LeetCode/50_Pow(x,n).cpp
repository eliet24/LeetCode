#include <iostream>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    double myPowRec(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
        {
            n = abs(n);
            return 1 / n;
        }
        if (n % 2 == 0)
        {
            return myPow(x * x, n / 2);
        }
        else
        {
            return x * myPow(x, n - 1);
        }
    }

    double myPow(double x, int n)
    {
        double num = 1;
        long temp = n;
        if (n < 0)
        {
            num = 1.0 / num;
        }
        if (temp < 0)
            temp = -temp;
        while (temp > 0)
        {
            if (temp % 2 == 1)
            {
                num = num * x;
                temp--;
            }
            else //temp % 2 == 0
            {
                x = x * x;
                temp /= 2;
            }
        }
        return num;
    }
};