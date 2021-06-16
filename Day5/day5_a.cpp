class Solution {
public:
    string getSmallestString(int n, int k) {
        k -= n;
        vector<int> val(n, 1);
        while(k>0)
        {
            --n;
            val[n] += min(25, k);
            k -= min(25, k);
        }
        string out = "";
        for(int c: val)
        {
            out += (char)('a' + c - 1);
        }
        return out;
    }
};