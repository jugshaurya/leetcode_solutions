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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left =  head;
        ListNode* right = head;
        ListNode* temp = head;
        
        int cnt = 1;
        while(cnt < k){
            left = left->next;
            temp = temp->next;
            cnt++;
        }
        
        while(temp and temp->next){
            right = right->next;
            temp = temp->next;
        }

        swap(left->val, right->val);
        return head;
    }
};