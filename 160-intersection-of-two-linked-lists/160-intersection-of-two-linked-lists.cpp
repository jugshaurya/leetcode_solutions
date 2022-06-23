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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL or headB == NULL) return NULL;
    ListNode* topA = headA;
    ListNode* topB = headB;
        
    while(headA != NULL and headB != NULL){
        headA = headA->next;
        headB = headB->next;
    }
        
    if(headA == NULL){
        // list A is smaller.    
    }else{
        swap(topA, topB);
        swap(headA, headB);
    }
        
    // topA will always point to smaller list.
    while(headB!=NULL){
        topB = topB->next;
        headB = headB->next;
    }
    
    while(true){
        if(topB == topA) return topB;        
        topB = topB->next;
        topA = topA->next;
    }
     
    return NULL;
    }
};