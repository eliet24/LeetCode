#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> v;
        if(nums.size()==0 || nums.size()==1 || nums.size()==2)
            return result;
        //sort the array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a, b, c, start, end;

        for(int i=0; i<n;i++)
        {
            a = nums[i];
            start = i + 1;
            end = n - 1;
            while(start < end)
            {
                b = nums[start];
                c = nums[end];
                if(a + b + c == 0){
                    v.push_back(a);
                    v.push_back(b);
                    v.push_back(c);
                    result.push_back(v);
                    while(start < n - 1 && nums[start] == nums[start + 1]) 
                        start++;
                    while(end > 0 && nums[end] == nums[end - 1]) 
                        end--;
                    start++;
                    end--;
                    v.pop_back();
                    v.pop_back();
                    v.pop_back();
                }
                else if(a + b + c > 0){
                    while(end > 0 && nums[end] == nums[end - 1])   
                        end--;
                    end--;
                }
                else{
                    while(start < n-1 && nums[start] == nums[start + 1])   
                        start++;
                    start++;
                }
            }
        }
        return result;   
    }
};

int main(){
    Solution sol;
    vector <int> v1 = {-1,0,1,2,-1,-4};
    vector <int> v2 = {0,1,1};
    vector <int> v3 = {0,0,0};
    vector<vector<int>> result = sol.threeSum(v1);
    cout<<"the 3sum vector is: ";
    for (vector i: result){
        cout<<"[";
        for(int j: i)
            cout << j << ' ';
        cout<<"] ";
    }
    cout<<endl<<"the 3sum vector is: ";
    vector<vector<int>> result1 = sol.threeSum(v2);
    for (vector i: result1)
        for(int j: i)
            cout << j << ' ';
    vector<vector<int>> result2 = sol.threeSum(v3);
    cout<<endl<<"the 3sum vector is: ";
    for (vector i: result2)
        for(int j: i)
            cout << j << ' ';

    return 0;
}