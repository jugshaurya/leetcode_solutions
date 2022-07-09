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


// Method2: using(Bottom Up)
class Solution {
public:
    // return {ifTakenMaxSumPossible, ifNotTakenMaxSumPossible}
    pair<int, int> helper(TreeNode* root){
        if(root == NULL) return {0, 0};
        
        auto leftAns = helper(root->left);
        auto rightAns = helper(root->right);
        
        int ifTakenRoot = root->val + leftAns.second + rightAns.second;
        int ifNotTakenRoot = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
        
        return {ifTakenRoot, ifNotTakenRoot};
    }
    
    int rob(TreeNode* root) {
        auto [a,b] = helper(root);
        return max(a, b);
    }
};

// Method1: using DP on trees(Top Down)
// class Solution {
// public:
//     map<pair<TreeNode*,bool>, int> mp;
//     int helper(TreeNode* root, bool canTake){
//         if(root == NULL) return 0;
        
//         if(mp.count({root, canTake}) == 1){
//             return mp[{root, canTake}];
//         }
//         // if root can be taken
//         if(canTake){
//             // i will take root
//             int opt1 = root->val + helper(root->left, false) + helper(root->right, false);
//             // i will still not take the root.
//             int opt2 = helper(root->left, true) + helper(root->right, true);
//             return mp[{root, canTake}] = max(opt1, opt2);
//         }
        
//         return mp[{root, canTake}] = helper(root->left, true) + helper(root->right, true);
//     }
    
//     int rob(TreeNode* root) {
//         return max(helper(root, true), helper(root, false));
//     }
// };