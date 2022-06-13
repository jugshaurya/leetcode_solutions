// using adjacency matrix
class Solution {
  public:
  int minTrioDegree(int n, vector<vector<int>>& edges) {
    
    // create adjacency matrix
    vector<vector<int>> gr(n + 1, vector<int>(n + 1, 0));
    for (auto edge : edges) {
      int x = edge[0];
      int y = edge[1];
      gr[x][y] = 1;
      gr[y][x] = 1;
    }
    
    // calculate degree of each vertex
    vector<int> degree(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        degree[i] += gr[i][j];
      }
    }

    // get all triplets and check it they form a 3-length cycle(trio)
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        for (int k = j+1; k <= n; k++) {
          if (gr[i][j] + gr[j][k] + gr[i][k] == 3) {
            ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
          };
        }
      }
    }

    return ans == 1e9 ? -1 : ans;
  }
};

// Method2 : using adjacency list: TLE
// using adjacency matrix

// class Solution {
//   public:
// int minTrioDegree(int n, vector<vector<int>>& edges) {
  //        vector<set<int> > gr(n+1);
  //         for(auto x: edges) {
  //             gr[x[0]].insert(x[1]);
  //             gr[x[1]].insert(x[0]);
  //         }

  //         vector<int> degree(n+1);
  //         for(int i=1;i<=n;i++){
  //             degree[i] = gr[i].size();
  //         }

  //         // get all triplets that are forming a cycle
  //         set<vector<int>> triplets;
  //         for(int i = 1; i<=n;i++) {
  //             for(int j = i+1; j<=n; j++){
  //                 // i and j must have edge to each other
  //                 if(find(gr[i].begin(),gr[i].end(),j)==gr[i].end()) continue;

  //                 int a = gr[i].size();
  //                 int b = gr[j].size();
  //                 vector<int> temp(a+b);
  //                 auto itToLastEl = set_intersection(gr[i].begin(),gr[i].end(),gr[j].begin(),gr[j].end(), temp.begin());
  //                 for(auto it=temp.begin(); it!=itToLastEl;it++){
  //                     // if *it contains edge to both i and j then it is 3length cycle
  //                     if(find(gr[*it].begin(),gr[*it].end(),i) == gr[*it].end()) continue;
  //                     if(find(gr[*it].begin(),gr[*it].end(),j) == gr[*it].end()) continue;
  //                     int minn = min({i,j,*it});
  //                     int maxx = max({i,j,*it});
  //                     int middle = i+j+*it - minn-maxx;
  //                     triplets.insert({minn,middle,maxx});
  //                 }
  //             }
  //         }

  //         if(triplets.size()==0) return -1;
  //         int ans = 1e9;
  //         for(auto x: triplets){
  //             ans = min(ans, degree[x[0]] + degree[x[1]] + degree[x[2]] - 6);
  //         }
  //         return ans;
  //     }
// };
