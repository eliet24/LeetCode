#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct Indeces
{
    int i = -1;
    int j = -1;
}Indeces;

class Solution{
    public:
    Indeces twoSum(int arr[], int target,int size){
        Indeces indeces;
        for (int i=0; i<size-1; i++)
        {
            if(arr[i] < target){
                for (int j=i+1; j<size; j++)
                {
                    if(arr[i] + arr[j] == target){
                        indeces.i = i;
                        indeces.j = j;
                    }    
                }        
            }
        } 
        return indeces;  
    }

    void twoSum2(int arr[], int target,int size, Indeces *indeces){
        
        for (int i=0; i<size-1; i++)
        {
            if(arr[i] < target){
                for (int j=i+1; j<size; j++)
                {
                    if(arr[i] + arr[j] == target){
                        indeces->i = i;
                        indeces->j = j;
                    }    
                }        
            }
        }   
    }
};

int main(){
    Indeces indeces;
    Indeces *ptr = &indeces;
    Solution sol;
    int arr[] = {1,2,3,4,10,11,12,5,5};
    int size = 9;
    int target = 10;
    //indeces = sol.twoSum(arr, target, size);
    sol.twoSum2(arr, target, size, ptr);
    printf("The Indeces are: %d %d", indeces.i, indeces.j);

    return 0;
}