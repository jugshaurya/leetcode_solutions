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
    // {height, diameter}
    pair<int, int> helper(TreeNode* root){
        
        if(root==NULL) return {0,0};
        
        auto leftAns = helper(root->left);
        auto rightAns = helper(root->right);
        
        int h = 1 + max(leftAns.first, rightAns.first);
        int d = max({leftAns.second, rightAns.second, leftAns.first + rightAns.first});
        return {h, d};
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
};