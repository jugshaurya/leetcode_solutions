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
    pair<TreeNode*,TreeNode*> helper(TreeNode* root){
        if(root == NULL) return {NULL, NULL};
        
        auto leftAns = helper(root->left);
        auto rightAns = helper(root->right);
        
        if(leftAns.first == NULL and rightAns.first == NULL) return {root, root};
        
        if(leftAns.first == NULL) {
            root->right = rightAns.first;
            root->left = NULL;
            return {root, rightAns.second};
        }  
        
        if(rightAns.first == NULL) {
            root->right = leftAns.first;
            root->left = NULL;
            return {root, leftAns.second};
        }
        
        root->right = leftAns.first;
        root->left = NULL;
        leftAns.second->right = rightAns.first;
        return {root, rightAns.second};
    }
    
    void flatten(TreeNode* root) {
        helper(root);
    }
};