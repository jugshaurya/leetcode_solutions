class Solution {
public:
    // Logic: If there exists a topological ordering => I can finish all the courses.
    // Tooplogical ordering exists if there is not directed cycle.
    // Method : Check if the given directed graph contains a cycle.
    // Can be done using BFS(Kahn's Algorithm)
    // can be done using DFS, check for the stack presence of a node.
    
    // Method 1: using BFS
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> gr(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto x: prerequisites){
            gr[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int f = q.front(); q.pop();
            for(auto nbr: gr[f]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        
        for(auto x: indegree){
            if(x != 0) return false;
        }
        
        return true;
        
        
    }

    // Method 2: using DFS
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
//     }
};