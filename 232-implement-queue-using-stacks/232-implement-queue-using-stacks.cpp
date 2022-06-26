// Follow up: Going for Amortized complexity
// Logic: I will always push to stack 1
// I will always pop from stack 2, If it is empty, I will transfer stack1 content to stack2.
// This way, for some operation , pop is O(#elements in stack 1), but most of the time it is constant.

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
            
    }
    // O(1)
    void push(int x) {
        s1.push(x);
    }
    
    //  Amortized O(1)
    int pop() {
        if(this->empty()) return -1;
        if(s2.empty()){
            // transfer all s1 to s2
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    //  Amortized O(1)
    int peek() {
        if(this->empty()) return -1;
        if(s2.empty()){
            // transfer all s1 to s2
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() and s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */