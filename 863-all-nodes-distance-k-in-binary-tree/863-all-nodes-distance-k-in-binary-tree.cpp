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
    void fillAtlevelK(TreeNode* root,int k, vector<int> &ans, string dir, int firstTime=1){
        if(root==NULL) return;
        if(k==0) ans.push_back(root->val);
        if(firstTime) {
            if(dir == "L"){
                fillAtlevelK(root->left, k-1, ans, dir, 0);
            }else{
                fillAtlevelK(root->right, k-1, ans, dir, 0);
            }
        }else{
            fillAtlevelK(root->left, k-1, ans, dir, 0);
            fillAtlevelK(root->right, k-1, ans, dir, 0);
        }
    }
    
    int distanceK(TreeNode* root, TreeNode* target, int k, vector<int> &ans) {
        if(root == NULL) return -1;
        if(root == target) {
            fillAtlevelK(root, k, ans, "L", 0);
            return 0;
        }
        
        int ldis = distanceK(root->left, target, k, ans);
        if(ldis != -1) {
            fillAtlevelK(root , k-ldis-1, ans, "R");
            return 1+ldis;        
        }
        
        int rdis = distanceK(root->right, target, k,ans);
           if(rdis != -1) {
            fillAtlevelK(root , k-rdis-1, ans, "L");
            return 1+rdis;        
        }

        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
        vector<int> ans;
        distanceK(root, target, k, ans);
        return ans;
        
    }
};