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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        TreeNode* left = pruneTree(root->left);
        TreeNode* right = pruneTree(root->right);
        root->left = left;
        root->right = right;
        
        if(left == NULL and right == NULL and root->val == 0){
            delete root;
            return NULL;
        }
        
        if(left == NULL and right == NULL and root->val == 1){
            return root;
        }
        
        return root;
    }
};