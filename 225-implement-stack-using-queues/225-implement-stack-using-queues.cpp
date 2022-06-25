// ===========================================================
// // Method1: using 2 queues
// // Push - O(1)
// // Pop, top - O(n)
// class MyStack {
// public:
//     queue<int> q1;
//     queue<int> q2;
    
//     MyStack() {
//     }
    
//     // Logic: I will always push to q1 and pop from q1
//     // O(1)
//     void push(int x) {
//         q1.push(x);
//     }
    
//     // O(n)
//     int pop() {
//         while(q1.size()>1){
//             int val = q1.front();
//             q1.pop();
//             q2.push(val);
//         }
//         int ans = q1.front();
//         q1.pop();
//         swap(q1, q2); // to maintain above Logic
//         return ans;
//     }
    
//     // O(n)
//     int top() {
//         int val = this->pop();
//         q1.push(val);
//         return val;
//     }
    
//     //  O(1)
//     bool empty() {
//         return q1.empty();    
//     }
// };

// ===========================================================

// Method2: using 2 queues
// Push - O(n)
// Pop, top - O(1)

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
    }
    
    // Logic: I will always push to q1 front
    // O(n)
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        swap(q1, q2);
    }
    
    // O(1)
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    // O(1)
    int top() {
        return q1.front();
    }
    
    //  O(1)
    bool empty() {
        return q1.empty();    
    }
};

// using one queue
// class MyStack {
// public:
//     MyStack() {
        
//     }
    
//     void push(int x) {
        
//     }
    
//     int pop() {
        
//     }
    
//     int top() {
        
//     }
    
//     bool empty() {
        
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */