/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *//**
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
    ListNode* findMiddleOfLL(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    } 
    
    ListNode* reverse(ListNode* head){
        if(head == NULL or head->next == NULL) return head;
        
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    } 
    
    void mergeAlternate(ListNode* head, ListNode* head2){
        
        ListNode* finalTail = head;
        int cnt = 1;
        while(head != NULL and head2 != NULL){
            if(cnt&1){
                ListNode* n = finalTail->next; 
                finalTail->next = head2;
                head2 = head2->next;
                head = n;
                cnt = cnt^1;
                finalTail = finalTail->next;
            }else{
                ListNode* n = finalTail->next; 
                finalTail->next = head;
                head = head->next;
                head2 = n;
                cnt = cnt^1;
                finalTail = finalTail->next;
            }
        }
        
        if(head==NULL) finalTail->next = head2;
        if(head2==NULL) finalTail->next = head;
        
    }
    
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        if(head->next == NULL) return;
        
        ListNode* middleNode = findMiddleOfLL(head);
        ListNode* secondHead = middleNode->next;
        middleNode->next = NULL;
        
        ListNode* newSecondHead = reverse(secondHead);
        mergeAlternate(head, newSecondHead);
    }
};