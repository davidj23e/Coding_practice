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
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        map<string, pair<TreeNode*,int>> M;
        duplicate(M, result, root);
        return result;
    }
    string duplicate(map<string, pair<TreeNode*,int>> &M, vector<TreeNode*> &result, TreeNode *root)     
    {
        if(!root)
            return "X";
        string L = duplicate(M, result, root->left);
        string R = duplicate(M, result, root->right);
        stringstream ss;
        ss << root->val << "L" << L << "R" << R;
        string key = ss.str();
        if(M.find(key)!=M.end())
        {
            if(M[key].second == 1)
                result.push_back(root);
            M[key].second += 1;
        }
        else
            M.insert({key, {root, 1}});
        return key;
    }
};