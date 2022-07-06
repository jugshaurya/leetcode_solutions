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
        
        int possibleMaxSumPassingFromRoot = max({root->val, leftAns.first, rightAns.first, leftAns.second + rightAns.second + root->val, rightAns.second + root->val, leftAns.second + root->val});
        int possibleMaxSumPassingContainingRoot = max({leftAns.second + root->val, rightAns.second + root->val, root->val});
        return {possibleMaxSumPassingFromRoot, possibleMaxSumPassingContainingRoot};
        
    }
    
    int maxPathSum(TreeNode* root) {
        return helper(root).first;
    }
};