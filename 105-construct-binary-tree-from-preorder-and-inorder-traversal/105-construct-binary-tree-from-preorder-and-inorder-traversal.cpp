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
    //  To make searching for index O(1)   
    map<int, int> inorderMap;
    
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE) {
        
        if(inS > inE) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preS]);
        // search in O(1) using map.
        int index = inorderMap[preorder[preS]];
        
        int itemsInLeftPart = index - inS;
        root->left = buildTreeHelper(preorder, inorder, preS + 1, preS + itemsInLeftPart, inS, index - 1);
        root->right = buildTreeHelper(preorder, inorder, preS + itemsInLeftPart + 1, preE, index + 1, inE);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++) inorderMap[inorder[i]] = i;
        return buildTreeHelper(preorder, inorder, 0, n-1, 0, n-1);
    }
};