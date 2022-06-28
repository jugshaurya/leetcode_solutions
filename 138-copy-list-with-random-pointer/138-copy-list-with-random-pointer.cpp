/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    void print(Node* head){
        cout<<endl;
        while(head) {cout<<head->val<<" "; head=head->next;}
        cout<<endl;
    }
    
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        
        Node* tmp = head; 
        while(tmp){
            Node* newNode = new Node(tmp->val);
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp = tmp->next->next;
        }

        tmp = head;
        while(tmp){
            tmp->next->random = tmp->random == NULL ? NULL : tmp->random->next;
            tmp = tmp->next->next;
        }
        
        Node* originalHead = head;
        Node* originalTail = head;
        Node* ansHead = head->next;
        Node* ansTail = head->next;
        
        while(originalTail and originalTail->next and ansTail and ansTail->next) {
            originalTail->next = originalTail->next->next;
            ansTail->next = ansTail->next->next;
            originalTail = originalTail->next;
            ansTail = ansTail->next;
        }
        
        ansTail->next = NULL;
        originalTail->next = NULL;
        
        return ansHead;
    }
};