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
    
    pair<int, int> helper(TreeNode* root) {
        if(root == NULL) return {-1001, -1001};
        
        auto leftAns = helper(root->left);
        auto rightAns = helper(root->right);
        
        int a = max({leftAns.first, rightAns.first, root->val, leftAns.second + root->val, rightAns.second + root->val, leftAns.second + root->val+ rightAns.second});
        int b = max({root->val, leftAns.second + root->val, rightAns.second + root->val});
        return {a, b};
    }
    
    int maxPathSum(TreeNode* root) {
        return helper(root).first;
    }
};