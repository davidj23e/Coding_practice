/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // int max_val = INT_MIN;
    int max_path(TreeNode*root, int &max_val)
    {
        if(!root)
            return 0;
        int left = max_path(root->left, max_val);
        int right = max_path(root->right, max_val);
        if(root->left && (root->val == root->left->val))
            left += 1;
        else
            left = 0;
        if(root->right && root->val == root->right->val)
            right += 1;
        else
            right = 0;
        max_val = max(max_val, left + right);
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode* root) {
        int max_val = 0;
        max_path(root, max_val);
        return max_val;
    }
};