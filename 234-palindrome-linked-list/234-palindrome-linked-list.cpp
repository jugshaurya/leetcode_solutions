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
    
    ListNode* reverse(ListNode* head){
        if(head == NULL or head->next == NULL) return head;

        ListNode* reversedHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return reversedHead;
    }
    
    ListNode* getMiddleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
           
        if(head==NULL or head->next==NULL) return head;
        ListNode* middleNode = getMiddleNode(head);
        ListNode* secondHead = middleNode->next;
        secondHead = reverse(secondHead);
        middleNode->next = NULL;
        
        while(head != NULL and secondHead != NULL){
            if(head->val!=secondHead->val) return false;
            head = head->next;
            secondHead = secondHead->next;
        }
        
        return true;
    }
};