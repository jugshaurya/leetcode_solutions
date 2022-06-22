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
    
    int length(ListNode* head){
        if(head == NULL) return 0;
        return 1 + length(head->next);
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL) return NULL;
        
        int n = length(head);
        k = k % n;
        
        if(k == 0) return head;
        
        int moves = n - k - 1;
        
        ListNode* temp = head;
        while(moves--) {
            temp = temp->next;
        }
        
        ListNode* newHead = temp->next;
        temp->next = NULL;

        ListNode* oldTail = newHead;
        while(oldTail->next){
            oldTail = oldTail->next;
        }
        oldTail->next = head;
        return newHead;
        
    }
};