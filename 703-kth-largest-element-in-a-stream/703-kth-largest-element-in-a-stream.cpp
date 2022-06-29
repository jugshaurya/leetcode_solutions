class KthLargest {
public:
    priority_queue<int> pq;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        
        // for min heap
        for(int i=0; i < k and i < n; i++) pq.push(-nums[i]);     
        
        for(int i = k; i < n; i++){
            if(nums[i] > -pq.top()){
                pq.pop();
                pq.push(-nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < k) {
            pq.push(-val);
            return -pq.top();
        }
        
        if(val > -pq.top()){
            pq.pop();
            pq.push(-val);
        }
        
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */