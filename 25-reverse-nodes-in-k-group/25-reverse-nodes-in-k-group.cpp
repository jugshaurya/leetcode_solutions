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
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
 
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL) return NULL;
        if(k == 1) return head;
        
        ListNode* groupTail = head;  
        
        int cnt = k - 1;
        while(cnt--){
            groupTail = groupTail->next;
            if(groupTail == NULL) return head;
        }
        
        ListNode* remainingHead = groupTail->next;
        groupTail->next = NULL;
        
        ListNode* newHead = reverse(head);
        head->next = reverseKGroup(remainingHead, k);
        return newHead;
    }
};