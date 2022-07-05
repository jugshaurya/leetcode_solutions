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
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         while(root!=NULL){
//             if(root->val > p->val and root->val > q->val) root = root->left;
//             else if(root->val < p->val and root->val < q->val  ) root=root->right;
//             else return root;
//         }
        
//         return NULL;
//     }
    
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        
        if(root->val == p->val or root->val == q->val) return root;
        
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        
        if(leftAns == NULL and rightAns==NULL) return NULL;
        if(leftAns == NULL) return rightAns;
        if(rightAns == NULL) return leftAns;
        
        return root;
        
    }
};