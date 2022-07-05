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
    void helper(TreeNode* root, string path, vector<string> &ans){
        if(root == NULL) return;    
        if(root->left == NULL and root->right == NULL){
            ans.push_back(path + to_string(root->val));
            return;
        }
        
        helper(root->left, path+to_string(root->val)+"->" , ans);
        helper(root->right,path+to_string(root->val)+"->", ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        helper(root, path, ans);
        return ans;
    }

};