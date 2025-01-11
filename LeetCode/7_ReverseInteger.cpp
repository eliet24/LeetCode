#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
#define INTEGER_MAX 2147483647
#define INTEGER_MIN (-INTEGER_MAX-1)

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        if(x / 10 == 0)
            return x;
        while(x != 0)
        {
            reversed = reversed * 10 + (x % 10);
            if (reversed < INTEGER_MIN || reversed > INTEGER_MAX){
                return 0;
            }
            x = x / 10;
        }
        return reversed;
    }
};

int main(){
    Solution sol;
    int x = -2147483648;
    cout<< "original number is: "<< x <<endl<<"Reversed number is: "<< sol.reverse(x)<<endl;
    return 0;
}