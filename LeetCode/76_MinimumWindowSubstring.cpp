#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> map_origin;
        unordered_map<char, int> map;
        string min_win = "";
        string window = "";
        int min_size = INT_MAX;
        if (s.size() < t.size())
        {
            return min_win;
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (map_origin.find(t[i]) != map_origin.end())
                map_origin[t[i]]++;
            else
                map_origin[t[i]] = 1;
        }
        map = map_origin;
        for (int i = 0; i < s.size(); i++)
        {
            if (map.find(s[i]) != map.end())
            {
                map[s[i]]--;
                if (map[s[i]] == 0)
                    map.erase(map.find(s[i]));
                window = window + s[i];
                if (map.empty() && window.size() < min_size)
                {
                    min_win = window;
                    min_size = min_win.size();
                    break;
                }
                for (int j = i + 1; j < s.size(); j++)
                {
                    window = window + s[j];
                    if (map.find(s[j]) != map.end())
                    {
                        map[s[j]]--;
                        if (map[s[j]] == 0)
                            map.erase(map.find(s[j]));
                    }
                    if (map.empty() && window.size() < min_size)
                    {
                        min_win = window;
                        min_size = min_win.size();
                        break;
                    }
                }
                if (map.empty() && window.size() < min_size)
                {
                    min_win = window;
                    min_size = min_win.size();
                }
                map = map_origin;
                window = "";
            }
        }
        return min_win;
    }


};

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    string s2 = "a", t2 = "a";
    string s3 = "a", t3 = "aa";
    string s4 = "ab", t4 = "a";
    Solution sol;
     cout << sol.minWindow(s, t) << endl;
     cout << sol.minWindow(s2, t2) << endl;
     cout << sol.minWindow(s3, t3) << endl;
    cout << sol.minWindow(s4, t4) << endl;
    return 0;
}