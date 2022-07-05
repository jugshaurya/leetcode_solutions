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

// Method2: Optimized
class Solution {
public:
    //  To make searching for index O(1)  
    // instead of using O(n) to search for the partition
    map<int, int> inorderMap;
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE) {
        
        if(preS > preE) return NULL;
        
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
        for(int i = 0; i<n; i++) inorderMap[inorder[i]] = i;
        return buildTreeHelper(preorder, inorder, 0, n-1, 0, n-1);
    }
};

// Method1: creating new arrays(extra memory)
// + using O(n) to search for the partition
// class Solution {
// public:
    
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         if(preorder.size()==0 || inorder.size()==0) return NULL;
        
//         int i=0;
//         for(; i<(int)(inorder.size()); i++){
//             if(inorder[i] == preorder[0]) break;
//         }
//         // cout<<i<<endl;
        
//         vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + i+1);
//         vector<int> rightPreorder(preorder.begin() + i+1, preorder.end());
//         vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
//         vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());
//         // cout<<leftPreorder.size()<<"d";
//         // cout<<rightPreorder.size()<<"d";
//         // cout<<leftInorder.size()<<"d";
//         // cout<<rightInorder.size()<<"d";
//         TreeNode* root  = new TreeNode(preorder[0]);
//         root->left = buildTree(leftPreorder, leftInorder);
//         root->right = buildTree(rightPreorder, rightInorder);
        
//         return root;
//     }
// };