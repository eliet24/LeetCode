#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;
        int mid, first = 1, last = x;
        while (first <= last)
        {
            mid = first + (last - first) / 2;
            if (mid == x / mid)
                return mid;
            else if (mid > x / mid)
                last = mid - 1;
            else
                first = mid + 1;
        }
        return last;
    }
};

int main()
{
    Solution sol;
    cout << sol.mySqrt(16) << endl;
    cout << sol.mySqrt(15) << endl;
    cout << sol.mySqrt(10) << endl;
    cout << sol.mySqrt(9) << endl;
    return 0;
}