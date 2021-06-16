class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> answer(nums.size(), -1);
        int val = 0;
        for(int x: nums)
            val ^= x;
        answer[0] = val ^ ( (1 << maximumBit) - 1);
        for(int i = 1; i < nums.size(); i++)
        {
            answer[i] =  answer[i - 1] ^ nums[nums.size() - i];
        }
        return answer;
    }
};