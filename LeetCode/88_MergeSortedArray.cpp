#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
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

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

int main()
{
    vector<int> num1 = {1, 2, 3, 0, 0, 0};
    vector<int> num2 = {2, 5, 6};
    Solution sol;
    sol.merge(num1, 3, num2, 3);
    cout << num1 << endl;
    return 0;
}