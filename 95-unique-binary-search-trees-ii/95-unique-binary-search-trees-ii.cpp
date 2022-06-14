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
    
    vector<TreeNode*> helper(int l, int r) {
        
        if(l == r){
            TreeNode* root = new TreeNode(l);
            return {root};
        }

        vector<TreeNode*> ans;
        for(int i = l; i <= r; i++){
            if(i == l){
                vector<TreeNode*> right = helper(i + 1, r); 
                for(auto y: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = NULL;
                    root->right = y;
                    ans.push_back(root);
                }
            } else if(i == r){
                vector<TreeNode*> left = helper(l, i-1); 
                for(auto x: left){
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = NULL;
                    ans.push_back(root);
                }
            }else {
                vector<TreeNode*> left = helper(l, i - 1);    
                vector<TreeNode*> right = helper(i + 1, r); 
                for(auto x: left){
                    for(auto y: right){
                        TreeNode* root = new TreeNode(i);
                        root->left = x;
                        root->right = y;
                        ans.push_back(root);
                    }
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};