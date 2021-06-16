class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, water = 0;
        while(i < j)
        {
            int curr = (j-i) * min(height[i], height[j]);
            water = max(water, curr);
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return water;
    }
};