class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        // find out degree of all vertixes
        // find maximum two values max1,max2
        // either the answer is max1+max1, max1+max1-1, max1+max2, max1+max2-1.
        
        // possible answer will be returned by the combination of max and second max degree.
        vector<vector<int> > gr(n);
        for(auto x: roads) {
            gr[x[0]].push_back(x[1]);
            gr[x[1]].push_back(x[0]);
        }

        vector<int> outdegree(n);
        int maxDeg = -1;
        for(int i=0;i<n;i++){
            outdegree[i] = gr[i].size();
            maxDeg = max(maxDeg, outdegree[i]);
        }
        
        int secondMaxDeg = -1;
        for(int i=0;i<n;i++){
            if(outdegree[i] == maxDeg) continue;
            secondMaxDeg = max(secondMaxDeg, outdegree[i]);
        }
        
        vector<int> possibleCandidates;
        for(int i=0;i<n;i++){
            if(outdegree[i] == maxDeg or outdegree[i]==secondMaxDeg){
                possibleCandidates.push_back(i);
            }
        }
        
        int ans = 0;
        for(auto x: possibleCandidates){
            for(auto y: possibleCandidates){
                if(x != y) {
                    if(find(gr[x].begin(), gr[x].end(), y) != gr[x].end())
                        ans = max(ans, outdegree[x] + outdegree[y] - 1);
                    else
                        ans = max(ans, outdegree[x] + outdegree[y]);
                }   
            }
        }
        
        return ans;
    }
};