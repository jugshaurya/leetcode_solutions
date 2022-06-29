#define pii pair<int,int>


class CustomComp {
public:
    
    bool operator()(pii a, pii b) {
        int distanceOfAFromOrigin = a.first*a.first + a.second*a.second;
        int distanceOfBFromOrigin = b.first*b.first + b.second*b.second;
        return  distanceOfAFromOrigin < distanceOfBFromOrigin;
    }    
};

class Solution {
public:
    int distance(pii a){
        int x = a.first;
        int y = a.second;
        
        return x*x + y*y;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pii, vector<pii>, CustomComp> pq;
        for(int i=0; i<k; i++){
            pq.push({points[i][0], points[i][1]});
        }
        
        int n = points.size();
        for(int i=k; i<n; i++){
            if(distance({points[i][0], points[i][1]}) < distance(pq.top())){
                pq.pop();
                pq.push({points[i][0], points[i][1]});
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto [x, y] = pq.top(); pq.pop();
            ans.push_back({x,y});
        }
        
        return ans;
    }
};