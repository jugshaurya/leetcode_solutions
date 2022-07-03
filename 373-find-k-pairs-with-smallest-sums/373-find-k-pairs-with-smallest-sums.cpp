struct Trip{
    int val;
    int i;
    int j;
    
    Trip(int val , int i, int j){
        this->val = val;
        this->i = i;
        this->j = j;
    }
};

class Cmp{
    public:
    bool operator()(Trip a, Trip b) {
        return a.val > b.val;
    }
};


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int m = nums1.size();
        int n = nums2.size();

        priority_queue<Trip, vector<Trip>, Cmp > pq;
        for(int i=0;i<m;i++) pq.push({nums1[i] + nums2[0], i, 0});
        
        vector<vector<int>> res;
        while(k-- and !pq.empty()){
            auto front = pq.top();
            pq.pop();
            res.push_back({nums1[front.i] , nums2[front.j]});
            if(front.j + 1 < n) {
                pq.push({nums1[front.i] + nums2[front.j + 1], front.i, front.j + 1});
            }
        }
        
        return res;
    }
};