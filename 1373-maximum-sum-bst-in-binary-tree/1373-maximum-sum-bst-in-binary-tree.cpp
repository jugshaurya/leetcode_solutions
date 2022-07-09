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

struct FourPair{
    int sum;
    bool isBst;
    int maxVal;
    int minVal;
};

class Solution {
public:
    FourPair helper(TreeNode* root, int & ans){
        
        if(root == NULL) return {0, true, INT_MIN, INT_MAX};
        FourPair leftAns = helper(root->left, ans);
        FourPair rightAns = helper(root->right, ans);
        
        int sum = leftAns.sum + rightAns.sum + root->val;
        bool isBst = leftAns.isBst and rightAns.isBst and root->val > leftAns.maxVal and root->val < rightAns.minVal;
        if(isBst) ans = max(ans, sum);
        int maxVal = max(root->val, rightAns.maxVal);
        int minVal = min(root->val, leftAns.minVal);
        return {sum , isBst, maxVal, minVal};
    }
    
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return max(0, ans);
    }
};