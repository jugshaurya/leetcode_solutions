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
    
    // Iterative
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
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* leftPointer = dummy;
        ListNode* rightPointer = dummy;
        
        while(--left){
            leftPointer = leftPointer->next;
        }
        
        while(right--){
            rightPointer = rightPointer->next;
        }
        
        ListNode* start = leftPointer->next;
        leftPointer->next = NULL;
        ListNode* end = rightPointer->next;
        rightPointer->next = NULL;
        ListNode* reversedHead = reverseList(start);
        leftPointer->next = reversedHead;
        start->next = end;
        
        ListNode* ans = dummy->next;
        dummy->next=NULL;
        delete dummy;
        return ans;
        
        
    }
};