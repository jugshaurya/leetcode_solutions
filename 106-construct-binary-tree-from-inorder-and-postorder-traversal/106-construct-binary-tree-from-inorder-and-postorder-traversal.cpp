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
    map<int, int> inorderMap;
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inS, int inE, int postS, int postE) {
        
        if(inS > inE) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postE]);
        // search in O(1) using map.
        int index = inorderMap[postorder[postE]];
        
        int itemsInLeftPart = index - inS;
        root->left = buildTreeHelper(inorder, postorder, inS, index - 1, postS, postS + itemsInLeftPart - 1);
        root->right = buildTreeHelper(inorder, postorder, index + 1, inE, postS + itemsInLeftPart , postE - 1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i<n; i++) inorderMap[inorder[i]] = i;
        return buildTreeHelper(inorder, postorder, 0, n-1, 0, n-1);
    }
};