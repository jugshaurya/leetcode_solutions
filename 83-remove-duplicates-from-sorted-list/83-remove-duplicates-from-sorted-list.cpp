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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        
        if(head->val == head->next->val) {
            ListNode* newHead = head->next;
            head->next = NULL;
            delete head;
            return deleteDuplicates(newHead);
        }
        
        head->next = deleteDuplicates(head->next);
        return head;
    }
};