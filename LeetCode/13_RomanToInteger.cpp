#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        map<char, int> map = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int i = 0;
        while(s[i] != '\0')
        {
            auto it = map.find(s[i]);
            auto it_next = map.find(s[i+1]);
            if(it->second < it_next->second){
                num = num + (it_next->second - it->second);
                i = i + 2;
            }
            else{
                num = num + it->second;
                i++;
            }
        }
        return num;
    }
};

int main(){
    Solution sol;
    string s1 = "III";
    string s2 = "LVIII";
    string s3 = "MCMXCIV";
    cout<<"Roman integer "<<s1<<" is: "<<sol.romanToInt(s1)<<endl;
    cout<<"Roman integer "<<s2<<" is: "<<sol.romanToInt(s2)<<endl;
    cout<<"Roman integer "<<s3<<" is: "<<sol.romanToInt(s3)<<endl;

    return 0;
}