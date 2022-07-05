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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int len = q.size();
            int n = len;
            double avg = 0;
            while(len--){
                auto front = q.front(); q.pop();
                avg += front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(avg/n);
        }
        
        return ans;
    }
};


