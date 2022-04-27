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

struct Tree{
    long long min, max;
    bool isbst;
};

class Solution {
public:
    
Tree checkBST(TreeNode *root){
    Tree t;
    if(!root){
        t.min = LONG_MAX;
        t.max = LONG_MIN;
        t.isbst = true;
    }
    else{
        Tree Left = checkBST(root->left);
        Tree Right = checkBST(root->right);
        t.min = min((long long)root->val, min(Left.min, Right.min));
        t.max = max((long long)root->val, max(Left.max, Right.max));
        t.isbst = Left.isbst and Right.isbst and Left.max < root->val and Right.min > root->val;
    }
    return t;
}
  
    bool isValidBST(TreeNode* root) {
      return checkBST(root).isbst;
    }
};


// bool isBST(Node * root){
