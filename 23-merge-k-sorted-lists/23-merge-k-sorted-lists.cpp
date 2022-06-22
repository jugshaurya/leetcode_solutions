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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        
        while(list1 != NULL and list2 != NULL){
            if(newHead == NULL){
                if(list1->val < list2->val){
                    newHead = newTail = list1;
                    list1 = list1->next;
                }else{
                    newHead = newTail = list2;
                    list2 = list2->next;
                }
            }else{
                if(list1->val < list2->val){
                    newTail->next = list1;
                    newTail = newTail->next;
                    list1  = list1->next;
                }else{
                    newTail->next = list2;
                    newTail = newTail->next;
                    list2 = list2->next;
                }
            }
        }
        
        if(list1 == NULL and list2 == NULL) return newHead;
        
        if(list1 == NULL) {
            if(newHead == NULL) return list2;
            newTail->next = list2;
            return newHead;
        }
        
        if(newHead == NULL) return list1;
        newTail->next = list1;
        return newHead;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        queue<ListNode*> q;
        for(auto x: lists) q.push(x);
        while(q.size() > 1) {
            ListNode* listA = q.front(); q.pop();
            ListNode* listB = q.front(); q.pop();
            q.push(mergeTwoLists(listA,listB));
        }
        
        if(q.empty()) return NULL;
        return q.front();
        
    }
};