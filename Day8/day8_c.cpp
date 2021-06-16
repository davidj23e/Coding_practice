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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return vector<vector<int>>();
        pair<vector<int>, TreeNode*> P{{root->val}, root};
        queue< pair<vector<int>, TreeNode*> > Q;
        
        vector<vector<int>> result;
        Q.push(P);
        while(!Q.empty())
        {
            pair<vector<int>, TreeNode*> node = Q.front();
            vector<int> temp = node.first;
            Q.pop();
            if(!node.second->left && !node.second->right && node.second->val == targetSum)
                result.push_back(temp);
            if(node.second->left)
            {
                int sum = (node.second->left->val + node.second->val);
                temp.push_back(node.second->left->val);
                node.second->left->val = sum;
                Q.push(make_pair(temp, node.second->left));
            }
            temp = node.first;
            if(node.second->right)
            {
                int sum = (node.second->right->val + node.second->val);
                temp.push_back(node.second->right->val);
                node.second->right->val = sum;
                Q.push(make_pair(temp, node.second->right));
            }
        }
        return result;
    }
};