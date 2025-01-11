#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

template <typename S> ostream& operator<<(ostream& os, const vector<S>& vector){
    for(auto element:vector){
        os<<element<<" ";
    }
    return os;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merg_arr(nums1.size()+nums2.size());
        int i=0, j=0, k=0;
        while(k < nums1.size()+nums2.size()){
            if(i < nums1.size() && j < nums2.size())
            {
                if(nums1[i] < nums2[j]){
                    merg_arr[k] = nums1[i];
                    i++;
                }
                else{
                    merg_arr[k] = nums2[j];
                    j++;
                }
            }
            else if (i < nums1.size())
            {
                merg_arr[k] = nums1[i];
                i++;
            }
            else if (j < nums2.size())
            {
                merg_arr[k] = nums2[j];
                j++;
            }
            k++;
        }
        cout<<"{ "<<merg_arr<<"} "<<"and median is: ";
        int median_index = (nums1.size() + nums2.size()) / 2;
        if((nums1.size()+nums2.size()) %2 ==0){
            return (merg_arr[median_index-1] + merg_arr[median_index]) /2.0;
        }
        else{
            return merg_arr[median_index];
        }
    }
};

int main(){
    Solution sol;
    vector <int> nums1 = {1,3};
    vector <int> nums2 = {2};
    vector <int> nums3 = {1,2};
    vector <int> nums4 = {3,4};
    cout<<"The merged array is: "<<sol.findMedianSortedArrays(nums1, nums2)<<endl;
    cout<<"The merged array is: "<<sol.findMedianSortedArrays(nums3, nums4)<<endl;
    return 0;
}