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
// // Method2: using 2 queues
// // Push - O(n)
// // Pop, top - O(1)
// class MyStack {
// public:
//     queue<int> q1;
//     queue<int> q2;
    
//     MyStack() {
//     }
    
//     // Logic: I will always push to q1's front
//     // O(n)
//     void push(int x) {
//         q2.push(x);
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }
        
//         swap(q1, q2);
//     }
    
//     // O(1)
//     int pop() {
//         int val = q1.front();
//         q1.pop();
//         return val;
//     }
    
//     // O(1)
//     int top() {
//         return q1.front();
//     }
    
//     //  O(1)
//     bool empty() {
//         return q1.empty();    
//     }
// };

// ===========================================================
// // FollowUp Method 1: Using only one queue
// // Push - O(n)
// // Pop, top - O(1)
// class MyStack {
// public:
    
//     queue<int> q;
//     MyStack() {
        
//     }
    
//     // push O(n)
//     // we push on rear end and will keep on poping front and reinsert into queue.
//     // how may times? size times.
//     // rather than pushing at the rear end
    
//     void push(int x) {
//         if(q.empty()) {
//             q.push(x);
//             return ;
//         }
        
//         int size = q.size();
//         q.push(x);
//         while(size--){
//             int val = q.front();
//             q.pop();
//             q.push(val);
//         }
//     }
    
//     // O(1)
//     int pop() {
//         int val = q.front();
//         q.pop();
//         return val;
//     }
    
//     // O(1)
//     int top() {
//         return q.front();
//     }
    
//     bool empty() {
//         return q.empty();
//     }
// };

// FollowUp: Method 2: Using only one queue
// Push - O(1)
// Pop, top - O(n)
class MyStack {
public:
    
    queue<int> q;
    MyStack() {
        
    }
    
    // push O(1)
    void push(int x) {
        q.push(x);
    }
    
    // O(n)
    int pop() {
        if(q.empty()) return -1;
        
        int size = q.size();
        size -= 1;
        while(size--) {
            int val = q.front();
            q.pop();
            q.push(val);
        }
        
        int val = q.front(); q.pop();
        return val;
    }
    
    // O(n)
    int top() {
        int val = this->pop();
        q.push(val);
        return val;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */