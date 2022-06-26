class MinStack {
public:
    vector<int> arr;
    vector<int> mini;
    
    MinStack() {
            
    }
    
    void push(int val) {
        arr.push_back(val);
        if(mini.empty()) mini.push_back(val);
        else mini.push_back(min(*mini.rbegin(), val));
    }
    
    void pop() {
        if(arr.size() == 0) return;
        arr.pop_back();
        mini.pop_back();
    }
    
    int top() {
        if(arr.size() == 0) return -1;
        return *(arr.rbegin());
    }
    
    int getMin() {
        if(arr.size()==0) return -1;
        return *(mini.rbegin());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */