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

// Method 1: usign NULL as marker
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> tmp;
        while(!q.empty()) {
            auto front = q.front(); q.pop();
            if(front == NULL) {
                if(!q.empty()) q.push(NULL);
                ans.push_back(tmp);
                tmp.clear();
            }else{
                tmp.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        
        return ans;
    }
};

// Method 2: Using while loop inside while loop
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         if(root == NULL) return {};
        
//         vector<vector<int>> ans;
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(!q.empty()) {
//             int len = q.size();
//             vector<int> tmp;
//             while(len--){
//                 auto front = q.front(); q.pop();
//                 tmp.push_back(front->val);
//                 if(front->left) q.push(front->left);
//                 if(front->right) q.push(front->right);
//             }
//             ans.push_back(tmp);            
//         }
        
//         return ans;
//     }
// };