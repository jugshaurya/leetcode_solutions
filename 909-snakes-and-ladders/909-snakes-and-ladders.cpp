class Solution {
  public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
      
    // flipping the board: used later see comments. :)
    reverse(board.begin(), board.end());
      
    queue<int> q;
    vector<bool> visited((n * n) + 1, false);
    vector<int> dist((n * n) + 1, 0);

    q.push(1);
    visited[1] = true;
    dist[1] = 0;

    while (!q.empty()) {
      int f = q.front();
      q.pop();

      for (int dice = 1; dice <= 6; dice++) {
        int nbr = f + dice;
        if(nbr <= n*n){
            
            // board is given from higher value to lower value 
            // flipping the board will come handy here.
            int nbrRow = (nbr-1) / n;
            int col = nbr - nbrRow * n - 1;  
            int nbrCol = nbrRow % 2 == 0 ? col : n - col-1;  

            int actualNbr = board[nbrRow][nbrCol] == -1 ? nbr : board[nbrRow][nbrCol];
            if (!visited[actualNbr]) {
              q.push(actualNbr);
              visited[actualNbr] = true;
                if(actualNbr==n*n) cout<<dist[f]<<endl; 
              dist[actualNbr] = dist[f] + 1;
            }
        }
      }
    }
        
    return visited[n*n] ? dist[n * n]: -1;
  }
};
