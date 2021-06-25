class Solution {
public:
    int maxVowels(string s, int k) {
        queue<int> Q;
        string vowels = "aeiou";
        int max_len = INT_MIN, curr_len = 0;
        for(int i=0;i<k;i++)
        {
            char c = s[i];
            if(vowels.find(c) != -1)
            {
                Q.push(1);    
                curr_len += 1;
            }
            else
            {
                Q.push(0);
            }                
        }
        max_len = max(max_len, curr_len);
        for(int i = 0+k; i< s.size(); i++)
        {
            int elem = Q.front();
            Q.pop();
            curr_len -= elem;
            char c = s[i];
            if(vowels.find(c) != -1)
            {
                Q.push(1);    
                curr_len += 1;
            }
            else
            {
                Q.push(0);
            }
            max_len = max(max_len, curr_len);
        }
        return max_len;
    }
};