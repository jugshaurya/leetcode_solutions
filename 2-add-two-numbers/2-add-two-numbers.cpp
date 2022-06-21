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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        
        ListNode* head1 = l1;
        ListNode* prev1 = NULL;
        ListNode* head2 = l2;
        ListNode* prev2 = NULL;
        
        while(l1 != NULL and l2 != NULL){
            int sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            l2->val = sum % 10;
            carry  = sum / 10;
            cout<<l1->val<<" ";
            prev1 = l1;
            prev2 = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1 == NULL and l2 == NULL) {
            if(carry == 1) {
                prev1->next = new ListNode(carry);
                return head1;
            }else{
                return head1;
            }
        } 
        
        if(l1 == NULL) {
            if(carry == 0){
                l2->val += carry;
                return head2;
            }else{
                while(l2 != NULL){
                    int sum = l2->val + carry;
                    l2->val = sum%10;
                    carry = sum/10;
                    prev2 = l2;
                    l2 = l2->next;
                }
                if(carry == 1) prev2->next = new ListNode(carry);
                return head2;
            }
        } 
        
        if(carry == 0){
            l1->val += carry;
            return head1;
        }
        
        while(l1 != NULL){
            int sum = l1->val + carry;
            l1->val = sum%10;
            carry = sum/10;
            prev1 = l1;
            l1=l1->next;
        }
        if(carry == 1) prev1->next = new ListNode(carry);
        return head1;
    }
};