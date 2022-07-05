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
    
    int helper(TreeNode* root, int k, int& cnt){
        
        if(root == NULL) return -1;
        int ans = helper(root->left, k, cnt);
        if(ans != -1) return ans;
        cnt++;
        if(cnt == k) return root->val;
        ans = helper(root->right, k, cnt);
        return ans;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return helper(root, k, count);
    }
};