class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> b1(26,0);
        vector<int> b2(26,0);
        for(char c: s1)
            b1[c - 'a']++;
        for(char c: s2)
            b2[c - 'a']++;
        return (checkSum(b1,b2) | checkSum(b2,b1));
    }
    bool checkSum(vector<int> &b1, vector<int> &b2)
    {
        int sum = 0;
        for(int i=0; i<26; i++)
        {
            sum += b1[i] - b2[i];
            if(sum>0)
                return false;
        }
        return true;
    }
};