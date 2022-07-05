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

// Method1: using Level order traversal(BFS)
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if(root == NULL) return {};
        
//         queue<TreeNode*> q;
//         q.push(root);
        
//         vector<int> ans;
//         while(!q.empty()){
//             int len = q.size();
//             while(len--){
//                 auto front = q.front(); q.pop();
//                 if(len == 0) ans.push_back(front->val);
//                 if(front->left) q.push(front->left);
//                 if(front->right) q.push(front->right);
//             }
//         }
        
//         return ans;
//     }
// };

// Method2: using Root, Right, Left Traversal (DFS)
class Solution {
public:
    void helper(TreeNode* root, int& maxLevelSeenSoFar, int level, vector<int> &ans) {
        if(root == NULL) return;
        
        if(level > maxLevelSeenSoFar) {
            ans.push_back(root->val);
            maxLevelSeenSoFar = level;
        };
        
        helper(root->right, maxLevelSeenSoFar, level + 1, ans);
        helper(root->left, maxLevelSeenSoFar, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxLevelSeenSoFar = -1;
        helper(root, maxLevelSeenSoFar, 0, ans);
        return ans;
    }
};