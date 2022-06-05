class Solution {
  public:
  vector<int> l[21 * 21];
  int no, n, m;
    
  void add_edge(int x, int y) {
    l[x].push_back(y);
  }
    
  int mincostbfs(int src, int dest) {
    queue<int> q;
    vector<bool> visited((n * n) + 1, false);
    vector<int> dist((n * n) + 1, 0);
      
    q.push(src);
    visited[src] = true;
    dist[src] = 0;
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      for (int nbr : l[f]) {
        if (!visited[nbr]) {
          q.push(nbr);
          visited[nbr] = true;
          dist[nbr] = dist[f] + 1;
        }
      }
    }
      
    for(auto x: dist) {
        cout<<x<<" ";
    }
      
    cout<<endl; 
    
     return dist[dest] == 0 ? -1 : dist[dest];
  }
    
  int snakesAndLadders(vector<vector<int>>& board) {
    n = board.size();
    m = board[0].size();
    no = 1;
    vector<int> b(441, 0);
    int c = 2;
    
    for (int i = n - 1; i >= 0; i--) {
      if (c % 2 == 0) {
        for (int j = 0; j < m; j++) {
          if (board[i][j] != -1) {
            b[no] = board[i][j] - no;
          }
          no++;
        }
      } else {
        for (int j = m - 1; j >= 0; j--) {
          if (board[i][j] != -1) {
            b[no] = board[i][j] - no;
          }
          no++;
        }
      }
      c++;
    }
    no--;
      
    // for(int i=1;i<no;i++) {
    //     cout<<b[i]<<" ";
    // }
      
    for (int i = 1; i <= n * n; i++) {
      for (int dice = 1; dice <= 6; dice++) {
        int v = i + dice;
        v += b[v];
        if (v <= n * n)
          add_edge(i, v);
      }
    }
      
    return mincostbfs(1, no);
  }
};

