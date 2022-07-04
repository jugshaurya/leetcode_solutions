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
    
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL and root2 == NULL) return true;
        if(root1 == NULL) return false;
        if(root2 == NULL) return false;
        
        return root1->val==root2->val and isMirror(root1->left, root2->right) and isMirror(root1->right, root2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL) return true;
        if(root->left == NULL and root->right==NULL) return true;
        if(root->left == NULL) return false;
        if(root->right == NULL) return false;
        
        return root->left->val == root->right->val and isMirror(root->left->left, root->right->right) and isMirror(root->left->right, root->right->left);
    }
};