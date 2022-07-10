/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void fillNodesAtKLevelBelow(TreeNode* root, int k, vector<int> &ans){
        
        if(root == NULL) return;
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        
        fillNodesAtKLevelBelow(root->left, k-1, ans);
        fillNodesAtKLevelBelow(root->right, k-1, ans);
    }
    
    int helper(TreeNode* root, TreeNode* target, int k, vector<int> &ans) {
        
        if(root == NULL) return -1;
        if(root == target){
            fillNodesAtKLevelBelow(root, k, ans);
            return 0;
        }
        
        int leftAns = helper(root->left, target, k, ans);
        if(leftAns != -1){
            int rootDistanceFromTarget = leftAns + 1;
            if(rootDistanceFromTarget == k) {
                ans.push_back(root->val);
            }else{
                fillNodesAtKLevelBelow(root->right, k - rootDistanceFromTarget - 1, ans);
            }
            return rootDistanceFromTarget;
        }
        
        int rightAns = helper(root->right, target, k, ans);
        if(rightAns != -1){
            int rootDistanceFromTarget = rightAns + 1;
            if(rootDistanceFromTarget == k) {
                ans.push_back(root->val);
            }else{
                fillNodesAtKLevelBelow(root->left, k - rootDistanceFromTarget - 1, ans);
            }
            return rootDistanceFromTarget;
        }
        
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        helper(root, target, k, ans);
        return ans;
    }
};