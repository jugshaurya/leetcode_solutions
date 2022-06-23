// class ListNode {
// public: 
//     int val;
//     ListNode* next;
    
//     ListNode(int val){
//         this->val = val;
//         next = NULL;
//     }
// };

class MyLinkedList {
public:
    
    ListNode* head;
    ListNode* tail;
    int size;
    
    MyLinkedList() {
        head = tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size) return -1; 
        ListNode* temp = head;
        
        while(index--){
            temp = temp->next;
        }
           
        return temp->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        if(head == NULL){
            head = tail = newNode;
        }else{
            head = newNode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(tail == NULL){
            head = tail = newNode;
            size++;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0) {addAtHead(val); return;}
        if(index == size) {addAtTail(val); return;}
        if(index > size) return;
        
        ListNode* temp = head;
        while(--index){
            temp = temp->next;
        }
        
        ListNode* nextNode = temp->next;
        ListNode* newNode = new ListNode (val);
        newNode->next = nextNode;
        temp->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        if(size == 0) return;
        if(index == 0 and size == 1){
            delete head;
            head=NULL; tail = NULL;
            size --;
            return;
        }
        
        if(index == 0){
            ListNode* newHead = head->next;
            delete head;
            head = newHead;
            size --;
            return;
        }
        
        ListNode* temp = head;
        while(--index){
            temp = temp->next;
        }
        if(temp->next->next==NULL){
            // deleting tail node
            delete temp->next;
            temp->next = NULL;
            tail = temp;
            
        }else{
            ListNode* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        size --;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */