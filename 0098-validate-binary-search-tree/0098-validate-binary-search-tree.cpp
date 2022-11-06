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

// Method 1
// struct ReturnIsBST{
//   bool isBST;
//   long long maxVal;
//   long long minVal;
// };

// class Solution {
// public:
//     ReturnIsBST isValidBSTHelper(TreeNode* root){
//       if(root == NULL) return {true, LONG_MIN, LONG_MAX};
    
//       ReturnIsBST leftAns = isValidBSTHelper(root->left);
//       ReturnIsBST rightAns = isValidBSTHelper(root->right);
      
//       bool a = leftAns.isBST and rightAns.isBST and root->val > leftAns.maxVal and root->val < rightAns.minVal;
//       long long b = max({leftAns.maxVal, rightAns.maxVal, (long long)root->val}); 
//       long long c = min({leftAns.minVal, rightAns.minVal, (long long)root->val}); 
      
//       return {a,b,c}; 
//     }
  
//     bool isValidBST(TreeNode* root) {
//       return isValidBSTHelper(root).isBST;
//     }
// };

// Method 2
class Solution {
public:
    // ll = leftlimit
    // rl = rightlimit
    bool isValidBSTHelper(TreeNode* root, long ll = LONG_MIN, long rl = LONG_MAX){
        if(root == NULL) return true;
        if(root->val <= ll or root->val >= rl) return false;
        return isValidBSTHelper(root->left, ll, root->val) and isValidBSTHelper(root->right, root->val, rl);
    }
  
    bool isValidBST(TreeNode* root) {
      return isValidBSTHelper(root);
    }
};