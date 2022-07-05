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
    map<int,int> postOrderMap;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder, int preS, int preE, int postS, int postE) {
        
        if(preS > preE) return NULL;
        
        // because I am accessing [preS + 1]th index;
        if(preS == preE) return new TreeNode(preorder[preS]);
        
        TreeNode* root = new TreeNode(preorder[preS]);
        
        // find the index of next element
        int index = postOrderMap[preorder[preS + 1]];
        int numberOfElementsInLeft = index - postS + 1;
        
        root->left = constructFromPrePost(preorder, postorder, preS + 1, preS + numberOfElementsInLeft, postS, index);
        root->right = constructFromPrePost(preorder, postorder, preS + numberOfElementsInLeft+1, preE, index + 1, postE - 1);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++) postOrderMap[postorder[i]] = i;
        return constructFromPrePost(preorder, postorder, 0, n-1, 0, n-1);
    }
};