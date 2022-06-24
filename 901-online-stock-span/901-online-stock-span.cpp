class StockSpanner {
public:
    
    // Logic: find index of prev strictly greater element.
    // if no prev greater is found store -1.
    // then ans is difference of `current price index` and `prev greater price index`  

    int queryCount;
    stack<pair<int, int>> s;

    StockSpanner() {
        queryCount = 0;
    }
    
    int next(int price) {
        while(!s.empty() and s.top().first <= price){
            s.pop();
        }
        
        int ans = queryCount;
        if(s.empty()) {
            ans -= (-1); 
        }else{
            ans -= s.top().second;
        }
        s.push({price, queryCount});
        queryCount++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */