/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Method 1:
// Can be done like LCA of BT, but it is O(n)
// class Solution {
// public:
//      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == NULL) return NULL;
        
//         if(root->val == p->val or root->val == q->val) return root;
        
//         TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
//         TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        
//         if(leftAns == NULL and rightAns==NULL) return NULL;
//         if(leftAns == NULL) return rightAns;
//         if(rightAns == NULL) return leftAns;
        
//         return root;
//     }
// };

// Method 2: use BST property and do it in O(H) (logn in some cases)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;
        
        if(p->val < root->val and q->val > root->val) return root;
        if(p->val < root->val and q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        if(p->val > root->val and q->val > root->val) return lowestCommonAncestor(root->right, p, q);
        // otherwise p or q's val equals root.
        return root;
    }
    
  
};
