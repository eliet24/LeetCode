#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <string.h>
#define MAX_CHARS 256
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map <char,int> m;
        int max = 0;
        int lastRepPos = -1;
        for(int i=0; i<s.size(); i++)
        {
            if(m.find(s[i]) != m.end() && lastRepPos < m[s[i]]){
                lastRepPos = m[s[i]];
            }
            if(i - lastRepPos > max){
                max = i -lastRepPos;
            }
        m[s[i]] = i;
        }
        return max;
    }

    //without using map 
    int longestSubstring(string s){
        int chars[MAX_CHARS];
        int max_len = 0;
        int lastRepPos = -1;
        memset(chars, -1, sizeof(chars));
        for (int i=0; i<s.size(); i++){
            if(chars[s[i]] != -1 && lastRepPos < chars[s[i]]){
                lastRepPos = chars[s[i]];
            }
            if(i-lastRepPos > max_len){
                max_len = i-lastRepPos;
            }
        chars[s[i]] = i;
        }
        return max_len;
    }
};

int main(){
    Solution sol;
    string s = "abcabcbb";
    cout << s << " : " << sol.lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << s << " : " << sol.lengthOfLongestSubstring(s) << endl;

    s = "bbabcdb";
    cout << s << " : " << sol.lengthOfLongestSubstring(s) << endl;

    s = "pwwkew";
    cout << s << " : " << sol.lengthOfLongestSubstring(s) << endl;

    return 0;

}