#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        while(left < right)
        {
            max_area = max(max_area, min(height[left],height[right]) * (right - left));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};

int main(){
    Solution sol;
    vector<int> a = {1, 5, 4, 3};
    vector<int> b = {3, 1, 2, 4, 5};
    cout<<"Max area for the given height vector is: "<<sol.maxArea(a)<<endl;
    cout<<"Max area for the given height vector is: "<<sol.maxArea(b)<<endl;
    return 0;
}