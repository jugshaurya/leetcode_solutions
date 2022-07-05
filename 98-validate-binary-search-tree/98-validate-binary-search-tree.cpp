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
    bool isValidBSTHelper(TreeNode* root, long leftLimit = LONG_MIN, long rightLimit = LONG_MAX){
        if(root == NULL) return true;
        if(root->val > leftLimit and root->val < rightLimit) {
            return isValidBSTHelper(root->left, leftLimit, root->val) and isValidBSTHelper(root->right, root->val, rightLimit);
        }
        return false;
    }
  
    bool isValidBST(TreeNode* root) {
      return isValidBSTHelper(root);
    }
};