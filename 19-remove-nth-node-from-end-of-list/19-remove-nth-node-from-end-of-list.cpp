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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL) return NULL;
        
        ListNode* slow = NULL;
        ListNode* fast = head;
        
        while(n--){
            fast = fast->next;
        }
        
        while(fast != NULL){
            if(slow == NULL){
                slow = head;
            }else{
                slow = slow -> next;
            }
            fast = fast -> next;
        }
        
        if(slow == NULL){
            ListNode* newHead = head->next;
            delete head;
            head = newHead;
            return head;
        }
        
        ListNode * temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
        
        
        
    }
};