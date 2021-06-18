class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int i = 0, reach = 0;
        for(i; (i<n) && (i<=reach); i++)
        {
            reach = max(i + nums[i], reach);
        }
        return i==n;
    }
};