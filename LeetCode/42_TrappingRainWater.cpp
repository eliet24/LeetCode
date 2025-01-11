#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int max_water = 0;
        if (height.size() <= 2)
            return 0;
        int n = height.size();
        int max_left = height[0];
        int max_right = height[n - 1];
        int left = 1;
        int right = n - 2;
        while (left <= right)
        {
            if (max_left < max_right)
            {
                if (height[left] > max_left)
                    max_left = height[left];
                else
                    max_water += max_left - height[left];
                left++;
            }
            else
            {
                if (height[right] > max_right)
                    max_right = height[right];
                else
                    max_water += max_right - height[right];
                right--;
            }
        }
        return  max_water;
    }

    int trapStack(vector<int>& heights) 
    {
        stack<int> s;
        s.push(heights[0]);
        int max = heights[0];
        int water = 0;
        int prev;
        int t;
        for(int i = 1; i<heights.size(); i++)
        {
            if(heights[i] > max)
            {
                while (s.size())
                {
                    prev = s.top();
                    s.pop();
                    water += max - prev;
                }
                max = heights[i];
            }
            s.push(heights[i]);
        }
        max = s.top();
        while(s.size())         //for water from max value to the end
        {
            t =s.top();
            s.pop();
            if(t > max)
                max = t;
            else
                water +=max - t;
        }
        return water;
    }
};

int main()
{
    Solution sol;
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << sol.trap(h) << endl;
    vector<int> h2 = {4, 2, 0, 3, 2, 5};
    cout << sol.trap(h2) << endl;
    cout << sol.trapStack(h) << endl;
    cout << sol.trapStack(h2) << endl;
    return 0;
}