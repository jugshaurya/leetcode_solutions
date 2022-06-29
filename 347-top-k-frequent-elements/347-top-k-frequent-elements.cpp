#define pii pair<int, int>

class CustomComp{
public:
    bool operator()(pii &a, pii &b){
        return a.second < b.second;
    }
};

class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        
        // O(n)
        for(auto x: nums) mp[x]++;
        
        // O(n)
        priority_queue<pii, vector<pii> ,CustomComp> pq(mp.begin(), mp.end());
        
        // O(klogN)
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};

