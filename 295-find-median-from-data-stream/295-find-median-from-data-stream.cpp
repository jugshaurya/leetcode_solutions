
class MedianFinder {
public:
    
    priority_queue<int, vector<int>, greater<int>> pqmin;
    priority_queue<int> pqmax;
    
    MedianFinder() {}
    
    // Logic: Shift elmenet from one heap to other if both heaps are not balanced.
    // i.e size difference is more than one => imbalance.
    void addNum(int num) {
        
        if(pqmax.empty() and pqmin.empty()){
            pqmin.push(num);
            return;
        } 

        if(pqmax.empty() and num <= pqmin.top()){
            pqmax.push(num);
            return;
        }
        
        if(pqmax.empty() and num > pqmin.top()){
            pqmin.push(num);
            int top = pqmin.top(); 
            pqmin.pop();
            pqmax.push(top);
            return;
        } 
        
        if(pqmin.empty() and num > pqmax.top()){
            pqmin.push(num);
            return;
        }
        
        if(pqmin.empty() and num <= pqmax.top()){
            pqmax.push(num);
            int top = pqmax.top(); 
            pqmax.pop();
            pqmin.push(top);
            return;
        } 
        
        if(num > pqmax.top()) {
            pqmin.push(num);
        } else {
            pqmax.push(num);
        }
        
        int a = pqmax.size();
        int b = pqmin.size();
        if(abs(a - b) > 1) {
            if(a > b){
                int top = pqmax.top(); 
                pqmax.pop();
                pqmin.push(top);
            }else{
                int top = pqmin.top(); 
                pqmin.pop();
                pqmax.push(top);
            }
        }
    }
    
    double findMedian() {
        int a = pqmax.size();
        int b = pqmin.size();
        
        if(a + b == 0) return 0;
        if(a + b == 1 and a == 1) return pqmax.top(); 
        if(a + b == 1 and b == 1) return pqmin.top(); 
        
        if((a + b) % 2 == 0) return (pqmax.top() + pqmin.top()) / 2.0; 
        return a > b ? pqmax.top(): pqmin.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */