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

// Method1: Using Level Order Traversal
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            long maxx = -1e10;
            while(sz--){
                auto front = q.front(); q.pop();
                maxx = max(maxx, (long)front->val);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(maxx);
        }
        return ans;
    }
};

// Method2: Using Postorder Traversal
// class Solution {
// public:
//     vector<int> largestValues(TreeNode* root) {
//         if(root == NULL) return {};
        
//         vector<int> leftAns = largestValues(root->left);
//         vector<int> rightAns = largestValues(root->right);
        
//         vector<int> ans;
//         ans.push_back(root->val);
        
//         int n = leftAns.size();
//         int m = rightAns.size();
        
//         int i = 0;
//         while(i < min(n,m)){
//             ans.push_back(max(leftAns[i], rightAns[i]));
//             i++;
//         }        
        
//         if(n > m) while(i < n) ans.push_back(leftAns[i++]);
//         else while(i < m) ans.push_back(rightAns[i++]);
        
//         return ans;
//     }
// };