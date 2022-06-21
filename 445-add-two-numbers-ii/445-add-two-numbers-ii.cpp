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

// FollowUp Solution: can do it without reversing using stack.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        
        stack<ListNode*> s1;
        stack<ListNode*> s2;

        while(l1){
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2);
            l2 = l2->next;
        }
        
        int carry = 0;
        while(!s1.empty() and !s2.empty()){
            ListNode* a = s1.top(); s1.pop();
            ListNode* b = s2.top(); s2.pop();
            int sum = a->val + b->val + carry;
            a->val = sum % 10;
            b->val = sum % 10;
            carry = sum / 10;
        }
        
        if(s1.empty() and s2.empty()) {
            if(carry == 1) {
                ListNode* n = new ListNode(carry);
                n->next = head1;
                head1 = n;
            }
            
            return head1;
        }
        
        if(s2.empty()){
            while(!s1.empty()){
                ListNode* a = s1.top(); s1.pop();
                int sum = a->val + carry;
                a->val = sum % 10;
                carry = sum / 10;
            }
            if(carry == 1) {
                ListNode* n = new ListNode(carry);
                n->next = head1;
                head1 = n;
            }
            
            return head1;   
        }
        
          
        if(s1.empty()){
            while(!s2.empty()){
                ListNode* b = s2.top(); s2.pop();
                int sum = b->val + carry;
                b->val = sum % 10;
                carry = sum / 10;
            }
            if(carry == 1) {
                ListNode* n = new ListNode(carry);
                n->next = head2;
                head2 = n;
            }
            
            return head2;   
        }
        
        assert("Ye kya Bawal ho gaya be!");
        return NULL;
    }
};