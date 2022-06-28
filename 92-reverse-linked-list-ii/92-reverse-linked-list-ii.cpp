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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = next;
        }
        
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL or head->next==NULL) return head;
        
        ListNode* leftPrev = NULL;
        ListNode* leftHead = head;
        
        while(--left) {
            leftPrev = leftHead;
            leftHead = leftHead->next;
        }
        
        ListNode* rightHead = head;
        while(--right){
            rightHead = rightHead->next;
        }
        
        ListNode* rightRemainingLL = rightHead->next;
        rightHead->next = NULL;
        
        if(leftPrev == NULL){
            ListNode* newHead = reverseList(head); 
            head->next = rightRemainingLL;
            return newHead;
        }
        
        leftPrev->next = NULL;
        ListNode* newHead = reverseList(leftHead);
        leftPrev->next = newHead; 
        leftHead->next = rightRemainingLL;
        return head;
    }
};