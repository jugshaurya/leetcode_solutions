/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    ListNode* getMiddle_minus1(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);
        
        ListNode* mid = getMiddle_minus1(head);
        ListNode* rightLL = mid->next->next;
        ListNode* toBeRoot = mid->next;
        TreeNode* root = new TreeNode(mid->next->val);        
        mid->next->next = NULL;
        mid->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(rightLL);
        mid->next = toBeRoot;
        mid->next->next = rightLL;
        return root;
    }
    
};