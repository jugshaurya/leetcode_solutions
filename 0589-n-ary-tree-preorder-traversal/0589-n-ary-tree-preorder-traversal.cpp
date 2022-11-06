/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        
        if(root == NULL) return {};
        
        vector<int> ans = {root->val};
        for(auto x: root->children){
            vector<int> tmp = preorder(x);
            for(auto x: tmp) ans.push_back(x);
        }
        
        return ans;
    }
};