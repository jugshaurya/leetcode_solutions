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

// Method 1: using extra five variable
// int currentLevel, int& px, int& py, int& lx, int& ly
// Method 2: using queue  + above five variable.
class Solution {
public:
    
    void helper(TreeNode* root, int x, int y, int currentLevel, int& px, int& py, int& lx, int& ly){
        
        if(root == NULL) return;
        if(root->val == x) lx = currentLevel;                 
        if(root->val == y) ly = currentLevel;    
        
        if((root->left and root->left->val == x) or (root->right and root->right->val==x)){
            px = root->val;
            lx = currentLevel + 1;
        }
        
        if((root->left and root->left->val == y) or (root->right and root->right->val==y)){
            py = root->val;
            ly = currentLevel + 1;
        }
        
        helper(root->left, x, y,currentLevel+1, px,py,lx,ly);
        helper(root->right, x, y,currentLevel+1, px,py,lx,ly);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int px=-1, py=-1, lx=-1, ly=-1;
        helper(root, x, y, 0, px,py,lx,ly);
        if(lx == -1 or ly == -1) {
            // x and y dont exist in tree
            assert("Wrong input");
            return false;
        }
        
        if(lx == ly and px != py) return true;
        return false;
    }
};