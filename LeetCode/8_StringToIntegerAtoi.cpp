#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>

#define INTEGER_MAX 2147483647
#define INTEGER_MIN -INTEGER_MAX-1
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        int num = 0;
        int i=0;
        int digit;
        for(;isspace(s[i]); i++);
        while(s[i] != '\0')
        {
            if(s[i]=='-' || s[i]=='+'){
                neg = s[i]=='-';
                i++;
            }
            if(isdigit(s[i]))
            {
                digit = s[i]-'0';
                if(neg){
                    if(-num < (INTEGER_MIN+ digit)/10 ){
                        return INTEGER_MIN;
                    }
                }
                else{
                    if(num > (INTEGER_MAX- digit) /10){
                        return INTEGER_MAX;
                    }
                }
                num = num*10 + digit;
            }
            i++;
        }
        return neg? -num:num;
    }
};

int main(){
    Solution sol;
    string s = "    abcfdfgh-2147483649dfgd  ";
    int y =sol.myAtoi(s);
    cout<< "Make integer fron string: "<< s <<endl<<sol.myAtoi(s)<<endl;

    return 0;
}