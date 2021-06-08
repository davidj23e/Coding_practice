#include <bits/stdc++.h>
using namespace std;
void backtrack(vector<string> &result, string s, int pos, int len)
{
    result.push_back(s);
    for(int i=pos; i<len; i++)
    {
        char c = s[i];
        if(c >= 'a' && c <= 'z')
        {
            char t = c - 'a' + 'A';
            s[i] = t;
            backtrack(result, s, i+1, len);
            s[i] = c;
        }
        if(c >= 'A' && c <= 'Z')
        {
            char t = c - 'A' + 'a';
            s[i] = t;
            backtrack(result, s, i+1, len);
            s[i] = c;
        }
    }
}
vector<string> letterCasePermutation(string s)
{
    int len = s.length();
    vector<string> result;
    backtrack(result, s, 0, len);
    return result;
        
}
int main()
{
    vector<string> out = letterCasePermutation("34554");
    cout << out.size() << endl;
    for(string val:out)
    {
        cout << val << endl;
    }
    return 0;
}