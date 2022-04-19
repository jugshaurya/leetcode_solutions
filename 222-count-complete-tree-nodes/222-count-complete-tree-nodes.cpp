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
    int findLeftMostHeight(TreeNode* root){
      int ans = 0;
      while(root){
        ans++;
        root = root->left;
      }
      return ans;
    }
  
    int findRightMostHeight(TreeNode* root){
      int ans = 0;
      while(root){
        ans++;
        root=root->right;
      }
      return ans;
    }
  
    int countNodes(TreeNode* root) {
      if(root == NULL) return 0;
      int leftMostHeight = findLeftMostHeight(root);
      int rightMostHeight = findRightMostHeight(root);
      if(leftMostHeight == rightMostHeight) return (1<<leftMostHeight) - 1;
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
};