/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void print(Node* head){
        if(head==NULL) return;
        while(head){
            cout<<head->val<<" ";
            head= head->next;
        }
        
    }
    
    Node* flatten(Node* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL and head->child == NULL) return head;
        
        if(head->child == NULL){
            Node* remainingHead = head->next;
            head->next = NULL;
            remainingHead->prev = NULL;

            Node* subAns = flatten(remainingHead);
            head->next = subAns;
            subAns->prev = head;
            return head;
        }
        
        Node* child = head->child;
        head->child = NULL;
        
        Node* subAnsChild = flatten(child);
        
        Node* remainingHead = head->next;
        head->next = NULL;
        if(remainingHead == NULL) {
            head->next = subAnsChild;
            subAnsChild->prev = head;
            return head;
        }
        remainingHead->prev = NULL;
        Node* subAnsNext = flatten(remainingHead);
        
        head->next = subAnsChild;
        subAnsChild->prev = head;
        Node* tmp = subAnsChild;
        while(tmp and tmp->next){
            tmp = tmp->next;
        }
        tmp->next = subAnsNext;
        subAnsNext->prev = tmp;
        
        print(head);
        return head;
        
    }
};