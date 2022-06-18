class Solution {
public:
    vector<bool> visited;
    vector<int> colorArray;

    bool isBipartiteHelper(vector<vector<int>>& gr, int src, int color){
        visited[src] = 1;
        colorArray[src] = color;
        
        for(auto nbr: gr[src]){
            if(!visited[nbr]){
               if(!isBipartiteHelper(gr, nbr, color ^ 1 ^ 2)) return false;         
            }else{
                if(colorArray[nbr] == color) return false;                
            }
        }
        
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited.clear();
        visited.assign(n, 0);
        colorArray.clear();
        colorArray.resize(n);
        for(int i= 0;i<n;i++){
            if(!visited[i]){
                int color = 1; 
                if(!isBipartiteHelper(graph, i, color)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};