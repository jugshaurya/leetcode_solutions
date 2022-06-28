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
    Node* flatten(Node* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL and head->child == NULL) return head;
        
        if(head->child == NULL){
            // break the links both next and prec
            Node* remainingHead = head->next;
            head->next = NULL;
            remainingHead->prev = NULL;
            
            // bring answer from recusion call
            Node* subAns = flatten(remainingHead);

            // connect both prev and next pointers back in place
            head->next = subAns;
            subAns->prev = head;
            
            return head;
        }
        
        // get answer for child
        Node* childHead = head->child;
        head->child = NULL;
        Node* subAnsChild = flatten(childHead);
        
        // if next does not exist, connect only the child answer
        if(head->next == NULL){
            head->next = subAnsChild;
            subAnsChild->prev = head;
            return head;
        }
        
        // otherwise both child and next exist
        Node* nextHead = head->next;
        head->next = NULL;
        nextHead->prev = NULL;
        Node* subAnsNext = flatten(nextHead);
        
        // combine the answer to get the result
        head->next = subAnsChild;
        subAnsChild->prev = head;
        
        Node* tmp = subAnsChild;
        while(tmp->next != NULL) tmp = tmp->next;
        
        tmp->next = subAnsNext;
        subAnsNext->prev = tmp;
        return head;
        
    }
};