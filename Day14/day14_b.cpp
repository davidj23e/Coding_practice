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
    void flatten(TreeNode* root) {
        TreeNode* temp1;
        TreeNode* temp2;
        if(root)
        {
            temp1 = root->left;
            temp2 = root->right;
            flatten(temp1);
            flatten(temp2);
            root->right = temp1;
            while(temp1 && temp1->right)
                temp1 = temp1->right;
            if(temp1)
                temp1->right = temp2;
            else
                root->right = temp2;
            root->left = nullptr;
        }
    }
};