#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


template <typename S>
ostream &operator<<(ostream &os, const vector<S> &vector)
{
    for (auto element : vector)
    {
        os << element << " ";
    }
    return os;
}

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            if(digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    vector<int> num1 = {1,2,3};
    vector<int> num2 = {4,3,2,1};
    vector<int> num3 = {9};
    Solution sol;
    cout << sol.plusOne(num1) <<endl;
    cout << sol.plusOne(num2) <<endl;
    cout << sol.plusOne(num3) <<endl;
}