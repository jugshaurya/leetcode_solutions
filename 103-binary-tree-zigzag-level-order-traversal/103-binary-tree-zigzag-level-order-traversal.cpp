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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> ans;
        bool toBeReverse = false;
        while(!q.empty()){
            
            int len = q.size();
            vector<int> currentLevel;
            while(len--){
                auto front = q.front(); q.pop();
                currentLevel.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            
            if(toBeReverse) {
                reverse(currentLevel.begin(), currentLevel.end());    
            }
            ans.push_back(currentLevel);
            toBeReverse = not toBeReverse;
        }
        return ans;
    }
};