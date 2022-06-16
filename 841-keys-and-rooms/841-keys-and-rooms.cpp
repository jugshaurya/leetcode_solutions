class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms, int src, vector<int> &visited){
        for(auto nbr: rooms[src]) {
            if(!visited[nbr]){
                visited[nbr] = 1;
                dfs(rooms, nbr, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,0);
        visited[0] = 1;
        dfs(rooms, 0, visited);
        
        for(auto x: visited) {
            if(x==0) return false;
        }
        
        return true;
    }
};
