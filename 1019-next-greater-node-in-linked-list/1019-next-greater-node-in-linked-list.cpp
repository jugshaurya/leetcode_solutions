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
    
    ListNode* reverseLL(ListNode* head){
        if(head == NULL or head->next == NULL) return head;
        
        ListNode* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        // reverse the list
        ListNode* reversedHead = reverseLL(head);
        stack<int> s;
        vector<int> ans;
        while(reversedHead){
            while(!s.empty() and s.top() <= reversedHead->val){
                s.pop();
            }

            if(s.empty()){
                ans.push_back(0);
                s.push(reversedHead->val);
            }else{
                ans.push_back(s.top());
                s.push(reversedHead->val);
            }
            reversedHead = reversedHead->next;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};