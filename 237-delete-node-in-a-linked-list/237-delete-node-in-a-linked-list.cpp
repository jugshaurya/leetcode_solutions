/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    
        // swap value of given node to next node
        swap(node->val, node->next->val);
        ListNode* deleteMe = node->next;
        node->next = node->next->next;
        delete deleteMe;
    }
};