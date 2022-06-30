
struct Triplet{
    int val;
    int x;
    int y;
};

class CustomComp{
public:
    bool operator()(Triplet &a, Triplet &b){
        return a.val > b.val;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        // we want minheap
        priority_queue<Triplet, vector<Triplet>, CustomComp> pq;
        pq.push({matrix[0][0], 0, 0});
        visited[0][0] = 1;
        vector<int> res;
        while(!pq.empty()){
            Triplet ans = pq.top(); pq.pop();
            res.push_back(ans.val);
            if(ans.x + 1 < n and ans.y < n and !visited[ans.x+1][ans.y]) {
                visited[ans.x+1][ans.y] = 1;
                pq.push({matrix[ans.x+1][ans.y], ans.x + 1, ans.y});
            }
            if(ans.x < n and ans.y + 1 < n and !visited[ans.x][ans.y+1]) {
                visited[ans.x][ans.y+1] = 1;
                pq.push({matrix[ans.x][ans.y+1], ans.x, ans.y + 1});
            }
        }
        
        // for(auto x: res) cout<<x<<" ";
        // cout<<endl;
        return res[k-1];
    }
};