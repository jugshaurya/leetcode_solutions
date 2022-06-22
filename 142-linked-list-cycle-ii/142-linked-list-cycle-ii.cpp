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
    ListNode *detectCycle(ListNode *head) {
       
        if(head == NULL) return NULL;
        
        // starting point must be same
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                break;
            }
        }
        
        if(fast == NULL or fast->next == NULL) {
            //No cycle found
            return NULL;
        }
        
        while(head != slow){
            head = head->next;
            slow = slow->next;
        }
        
        return head;
    }
};