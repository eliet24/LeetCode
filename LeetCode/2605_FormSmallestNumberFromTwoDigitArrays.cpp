#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctype.h>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2)
    {
        int s_len = min(nums1.size(), nums2.size());
        int l_len = max(nums1.size(), nums2.size());
        vector<int> v1(10, 0), v2(10, 0);
        int min_v1 = 10;
        int min_v2 = 10;
        for (int i = 0; i < s_len; i++)
        {
            v1[nums1[i]]++;
            v2[nums2[i]]++;
        }
        if (nums1.size() < nums2.size())
        {
            for (int i = s_len; i < l_len; i++)
            {
                v2[nums2[i]]++;
            }
        }
        else
        {
            for (int i = s_len; i < l_len ; i++)
            {
                v1[nums1[i]]++;
            }
        }
        for(int i = 1; i <= 9; i++)
        {
            if(v1[i] && v2[i])
                return i;
            if(min_v1 == 10 && v1[i] && i < min_v1)
                min_v1 = i;
            if(min_v2 == 10 && v2[i] && i < min_v2)
                min_v2 = i;
        }
        if(min_v1 < min_v2)
            return (min_v1*10 + min_v2);
        else
            return (min_v2*10 + min_v1);
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {3,4,7,1,5};
    vector<int> v2 = {4,2,3,5,1,6,8};
    cout << sol.minNumber(v1, v2);
    return 0;
}