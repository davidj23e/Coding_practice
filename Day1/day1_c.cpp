#include<bits/stdc++.h>
using namespace std;
int maxLength(vector<string>& arr)
{
    int res = 0;
    vector<bitset<26>> m = {bitset<26>()};
    for(string s: arr)
    {
        bitset<26> temp;
        for(char c: s)
            temp.set(c-'a');
        if (temp.count() < s.size())
            continue;
        if (m.size() == 0)
        {
            m.push_back(temp);
            res = temp.count();
        }
        else
        {
            for(int i=m.size()-1; i>=0;i--)
            {
                if((m[i] & temp).any())
                    continue;
                m.push_back((m[i] | temp));
                res = max(res, int(temp.count() + m[i].count()));
            }
        }
    }
    return res;
}
int main()
{
    vector<string> arr = {"a", "abc", "d", "de", "def"};
    int out = maxLength(arr);
    cout << out << endl;
}