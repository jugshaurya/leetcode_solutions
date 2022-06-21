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
        if(head==NULL or head->next==NULL) return head;
        
        ListNode* temp = head;
        while(temp != NULL and temp->next != NULL and  temp->val == temp->next->val){
            ListNode* n = temp->next;
            delete temp;
            temp = n;           
        }
        
        if(temp == head){
            // no duplicate found
            head->next = deleteDuplicates(head->next);
            return head;
        }
        
        // otherwise, duplicate exist from head to temp
        ListNode* n = temp->next;
        delete temp;
        return deleteDuplicates(n);
        
    }
};