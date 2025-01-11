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
    string longestCommonPrefix(vector<string>& strs) {
        string common_prefix;
        string word;
        string w;
        bool match = true;
        for(int i=0; i<strs[0].size();i++)
        {
            w = strs[0].substr(0, i);
            for(int j=1; j<strs.size(); j++)
            {
                if(w != strs[j].substr(0,i)){
                    match = false;
                    break;
                }
            }
            if(!match)
                return word;
            word = w;
        }
        return word;
    }
};

int main(){
    Solution sol;

    vector<string> v {"abab","aba","abc"};
    cout <<"longest common sequence is: "<< sol.longestCommonPrefix(v) <<endl;
    return 0;
}