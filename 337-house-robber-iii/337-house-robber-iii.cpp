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
    map<pair<TreeNode*,bool>, int> mp;
    int helper(TreeNode* root, bool canTake){
        if(root == NULL) return 0;
        
        if(mp.count({root, canTake}) == 1){
            return mp[{root, canTake}];
        }
        // if root can be taken
        if(canTake){
            // i will take root
            int opt1 = root->val + helper(root->left, false) + helper(root->right, false);
            // i will still not take the root.
            int opt2 = helper(root->left, true) + helper(root->right, true);
            return mp[{root, canTake}] = max(opt1, opt2);
        }
        
        return mp[{root, canTake}] = helper(root->left, true) + helper(root->right, true);
    }
    
    int rob(TreeNode* root) {
        return max(helper(root, true), helper(root, false));
    }
};