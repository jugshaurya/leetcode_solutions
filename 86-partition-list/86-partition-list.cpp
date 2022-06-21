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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* lesserHead = NULL;
        ListNode* lesserTail = NULL;
        ListNode* greaterHead = NULL;
        ListNode* greaterTail = NULL;
        
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                if(lesserHead == NULL) {
                    lesserHead = lesserTail = temp;
                    temp = temp->next;
                } else {
                    lesserTail->next = temp;
                    lesserTail = lesserTail -> next;
                    temp = temp->next;
                } 
            }else{
                if(greaterHead == NULL) {
                    greaterHead = greaterTail = temp;
                    temp = temp->next;
                } else {
                    greaterTail->next = temp;
                    greaterTail = greaterTail -> next;
                    temp = temp->next;
                } 
            }
        }
        
        if(lesserTail == NULL) return greaterHead;
        lesserTail->next = greaterHead;
        
        if(greaterTail == NULL) return lesserHead;
        greaterTail->next = NULL;
        
        return lesserHead;
    }
};