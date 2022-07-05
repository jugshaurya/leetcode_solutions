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

#define pii pair<int,int> 

class Solution {
public:
    
    void helper(TreeNode* root, int leveli, int levelj, map<int, vector<pii> >&mp) {
        if(root==NULL) return;
        mp[levelj].push_back({root->val, leveli});
        helper(root->left, leveli + 1, levelj - 1 , mp);
        helper(root->right, leveli + 1, levelj + 1 , mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // j -> [{val, i}, {val, i}, ... ]
        map<int, vector<pii> > mp;
        helper(root, 0, 0, mp);
        
        vector<vector<int>> ans;
        for(auto x: mp){
            sort(x.second.begin(), x.second.end(), [](pii a, pii b){
                if(a.second != b.second) return a.second < b.second;
                return a.first < b.first;
            });
            
            vector<int> tmp;
            for(auto y: x.second) tmp.push_back(y.first);
            ans.push_back(tmp);
        }
        return ans;
    }
};