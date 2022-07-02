class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        for(auto x: s) mp[x]++;
        
        priority_queue<pair<int, char>> pq;
        for(auto x: mp){
            pq.push({x.second, x.first});
        }
        
        string ans;
        while(!pq.empty()){
            auto a = pq.top(); pq.pop();
            if(pq.empty()){
                if(a.first == 1) {
                    ans += a.second;
                    return ans;
                } else return "";
            }
            auto b = pq.top(); pq.pop();
            ans += a.second;
            ans += b.second;
            if(a.first > 1) pq.push({a.first - 1, a.second });
            if(b.first > 1) pq.push({b.first - 1, b.second });
        }
        
        return ans;
    }
};