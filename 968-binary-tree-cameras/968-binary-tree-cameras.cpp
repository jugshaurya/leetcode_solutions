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

const int INF = 1e9;
class Solution {
public:
    
    pair<int, pair<int, int> >helper(TreeNode* root){
        if(root == NULL) return {0, {0, INF}};
        
        auto leftAns = helper(root->left);
        auto rightAns = helper(root->right);
        
        int a = leftAns.first;
        int b = leftAns.second.first;
        int c = leftAns.second.second;
        
        int d = rightAns.first;
        int e = rightAns.second.first;
        int f = rightAns.second.second;
        
        int opt1 = b + e;
        int opt2 = min(c + min(e, f), f + min(b, c) );
        int opt3 = 1 + min(a, min(b,c)) + min(d, min(e,f));
        return {opt1,  {opt2 , opt3}};
    }
    
    int minCameraCover(TreeNode* root) {
        auto ans = helper(root);
        return min(ans.second.first, ans.second.second);
    }
};