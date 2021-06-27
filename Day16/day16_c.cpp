class Solution {
public:
    int binary_search(vector<int> &nums, int target, int lo, int hi)
    {
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = nums.size();
        if(nums[l-1] < nums[0])
        {
            if(target > nums[l-1] && target < nums[0] )
                return -1;
            else
            {
                int i = 0;
                while(i<l)
                {
                    if(nums[i] == target)
                        return i;
                    i++;
                    if(i<l && nums[i] < nums[i-1])
                        break;
                }
                return binary_search(nums, target, i, l-1);
            }
            
        }
        else
        {
            return binary_search(nums, target, 0, l-1);
        }
        return -1;
    }
};