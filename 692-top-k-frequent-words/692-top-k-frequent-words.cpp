#define psi pair<string, int>

class Cmp{
    public: 
    bool operator()(psi a, psi b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(auto x: words) mp[x]++;
        
        priority_queue<psi, vector<psi>, Cmp > pq(mp.begin(), mp.end());
        
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};