#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    unordered_map<char, string> initMap()
    {
        unordered_map<char, string> digitToChar;
        digitToChar['2'] = "abc";
        digitToChar['3'] = "def";
        digitToChar['4'] = "ghi";
        digitToChar['5'] = "jkl";
        digitToChar['6'] = "mno";
        digitToChar['7'] = "pqrs";
        digitToChar['8'] = "tuv";
        digitToChar['9'] = "wxyz";
        return digitToChar;
    }

    void dfs(unordered_map<char, string> digit_to_char, queue<string> &result, string digits)
    {
        string s;
        if (digits == "")
            return;
        int size = result.size();
        for (int i = 0; i < size; i++)
        {
            s = result.front();
            result.pop();
            for (auto c : digit_to_char[digits[0]])
            {
                result.push(s + c);
            }
        }
        dfs(digit_to_char, result, digits.substr(1));
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> results;
        if (digits == "")
            return results;
        unordered_map<char, string> digit_to_char = initMap();
        queue<string> comb;
        comb.push("");
        dfs(digit_to_char, comb, digits);
        while(!comb.empty())
        {
            results.push_back(comb.front());
            comb.pop();
        }
        return results;
    };
};

void printVector(vector<string>& ss){
    cout << "{ ";
    for(int i=0; i<ss.size(); i++){
        if (i>0) 
            cout << ", "; 
        cout << ss[i];
    }
    cout << " }" << endl;
}

int main()
{
    string s="23";
    Solution sol;
    vector<string> ss = sol.letterCombinations(s);
    printVector(ss);
    return 0;
}