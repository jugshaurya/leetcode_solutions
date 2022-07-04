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
    // reverse of inorder will work here
    void updateBygreaterSumAndReturnTotalSum(TreeNode* root, int& rightSum) {
        if(root == NULL) return;
        
        updateBygreaterSumAndReturnTotalSum(root->right, rightSum);
        root->val += rightSum;
        rightSum = root->val;
        updateBygreaterSumAndReturnTotalSum(root->left, rightSum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int rightSum = 0;
        updateBygreaterSumAndReturnTotalSum(root, rightSum);
        return root;
    }
};