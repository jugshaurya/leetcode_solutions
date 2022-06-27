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
    ListNode* insert(ListNode* node, ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        while(temp and node->val > temp->val){
            prev = temp;
            temp = temp->next;
        }
        
        // temp points to the node with >= value than node value
        // prev point to node before that
        if(prev == NULL) {
            node->next = head;
            head = node;
            return head;
        }
        
        node->next = temp;
        prev->next = node;
        return head;
    }   
    
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;

        ListNode* sortedHead = head;
        ListNode* notSortedHead = head->next;
        sortedHead->next = NULL;
        while(notSortedHead) {
            ListNode* node = notSortedHead;
            notSortedHead = notSortedHead->next;
            node->next = NULL;
            sortedHead = insert(node, sortedHead);
        }
        
        return sortedHead;
    }
};