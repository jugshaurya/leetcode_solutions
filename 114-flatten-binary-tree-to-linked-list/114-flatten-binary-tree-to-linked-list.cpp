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
    
    pair<TreeNode*, TreeNode*> helper(TreeNode* root){
        if(root == NULL) return {NULL,NULL};
        
        auto leftLL = helper(root->left);
        auto rightLL = helper(root->right);
        
        if(leftLL.first==NULL and rightLL.first==NULL) return {root, root};
        
        TreeNode* head = root;
        
        if(leftLL.first==NULL) {
            head->right = rightLL.first;
            return {head, rightLL.second};
        }
            
        if(rightLL.first==NULL) {
            head->left=NULL;
            head->right = leftLL.first;
            return {head, leftLL.second};
        }
        
        root->right = leftLL.first;
        root->left=NULL;
        leftLL.second->right = rightLL.first;
        return {head, rightLL.second};
    }
    
    void flatten(TreeNode* root) {
        helper(root);
    }
};