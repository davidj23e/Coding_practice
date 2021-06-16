#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construcTree(nums, 0, nums.size()-1);
    }
    TreeNode * construcTree(vector<int> &nums, int l, int r)
    {
        if(l>r)
            return nullptr;

        int maxpos = get_max(nums, l, r);
        TreeNode *root = new TreeNode(nums[maxpos]);
        root->left = construcTree(nums, l, maxpos - 1);
        root->right = construcTree(nums, maxpos + 1, r);
        return root;
    }
    int get_max(vector<int> &nums, int l, int r)
    {
        int maxpos = l;
        for(int i=l+1;i<=r;i++)
        {
            if(nums[maxpos] < nums[i])
                maxpos = i;
        }
        return maxpos;
    }
};
int main()
{
    Solution ob;
    vector<int> nums{3,2,1,6,0,5};
    TreeNode *val = ob.constructMaximumBinaryTree(nums);
    cout << val->val << endl;
    return 0;
}