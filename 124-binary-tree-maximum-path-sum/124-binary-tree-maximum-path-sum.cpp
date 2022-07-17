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

struct Pair{
    int a; // maxPathSum;
    int b; // maxLinePathSum;
};

class Solution {
public:
    
    Pair helper(TreeNode* root) {
        if(root == NULL) return {-1001, -1001};
        
        Pair l = helper(root->left);
        Pair r = helper(root->right);
        
        int maxPathSum = max({l.a, r.a, root->val, root->val + l.b, root->val + r.b , root->val + l.b + r.b});
        int maxLineSum = max({root->val, root->val + l.b, root->val + r.b});
        
        return {maxPathSum, maxLineSum};
    }
    
    int maxPathSum(TreeNode* root) {
        return helper(root).a;
    }
};