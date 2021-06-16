class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(5000000+1, 0);
        int count = 0;
        for(int i = 2; i < n; i++)
        {
            if(prime[i] == 0)
                count++;
            else
                continue;
            for(int idx = 2 * i; idx <= n; idx += i)
            {
                prime[idx]++;
            }
        }
        return count;
        
    }
};