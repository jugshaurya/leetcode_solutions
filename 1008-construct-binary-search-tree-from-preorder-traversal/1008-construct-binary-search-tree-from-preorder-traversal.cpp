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
    
    TreeNode* bstFromPreorderHelper(vector<int>& preorder,int &i, int leftLimit=INT_MIN, int rightLimit=INT_MAX) {
        int n = preorder.size();
        if(i == n) return NULL;
        
        if(preorder[i] > leftLimit and preorder[i] < rightLimit){
            TreeNode* root = new TreeNode(preorder[i]);
            i++;
            root->left = bstFromPreorderHelper(preorder, i, leftLimit, root->val);
            root->right = bstFromPreorderHelper(preorder, i, root->val, rightLimit);
            return root;
        }
        return NULL;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return bstFromPreorderHelper(preorder, i);
    }
    
    
};