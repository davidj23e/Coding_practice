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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode* node = Q.front();
            Q.pop();
            if(!node->left && !node->right && node->val == targetSum)
                return true;
            if(node->left)
            {
                node->left->val += node->val;
                Q.push(node->left);
            }
            if(node->right)
            {
                node->right->val += node->val;
                Q.push(node->right);
            }
        }
        return false;
    }
};