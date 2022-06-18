class Solution {
public:
    bool bipartite;
    vector<bool> visited;
    vector<int> color;
    vector<vector<int>> gr;
    
    void isBipartiteHelper(int src, int c){
        visited[src] = 1;
        for(auto nbr: gr[src]){
            if(visited[nbr] and color[nbr] == c) { bipartite = false; return;}
            if(!visited[nbr]) {
                color[nbr] = c^1^2;
                isBipartiteHelper(nbr, c^1^2);
            }         
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        gr = graph;
        visited.clear();
        visited.assign(n, 0);
        color.clear();
        color.assign(n, 0);
        bipartite = true;
        
        for(int i= 0;i<n;i++){
            if(!visited[i]) isBipartiteHelper(i, 1);
        }

        return bipartite;
    }
};