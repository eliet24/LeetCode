#include <iostream>
#include <string>
using namespace std;

class SolutionRecu
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string result;
        string tmp = countAndSay(n - 1);
        char c = tmp[0];
        int count = 1;
        for (int i = 1; i < tmp.size(); i++)
        {
            if (tmp[i] == c)
                count++;
            else
            {
                result += to_string(count);
                result.push_back(c);
                count = 1;
                c = tmp[i];
            }
        }
        result += to_string(count);
        result.push_back(c);
        return result;
    }
};

class Solution
{
public:
    string find(int n, string &str)
    {
        if (n == 1)
            return "1";
        int count = 1;
        string res = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != str[i + 1])
            {
                res.push_back(count + '0');
                res.push_back(str[i]);
                count = 1;
            }
            else
                count++;
        }
        return res;
    }

    string countAndSay(int n)
    {
        string str;
        for (int i = 1; i <= n; i++)
        {
            str = find(i, str);
        }
        return str;
    }
};

int main()
{
    SolutionRecu solr;
    cout << solr.countAndSay(1) << endl;
    cout << solr.countAndSay(4) << endl;
    Solution sol;
    cout << sol.countAndSay(1) << endl;
    cout << sol.countAndSay(4) << endl;
    return 0;
}