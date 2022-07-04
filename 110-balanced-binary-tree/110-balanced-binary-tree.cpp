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
    
    pair<bool, int> isBalancedHelper(TreeNode* root) {
        if(root == NULL) return {true, 0}; 
        
        auto leftAns = isBalancedHelper(root->left);
        auto rightAns = isBalancedHelper(root->right);
        
        return { leftAns.first and rightAns.first and abs(leftAns.second-  rightAns.second) <= 1 , 1 + max(leftAns.second, rightAns.second)};
    }
    
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).first;   
    }
};