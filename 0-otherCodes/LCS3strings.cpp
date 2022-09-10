// https://www.learning.algozenith.com/problems/LCS-of-3-Strings-900

/*
  Author : Shaurya Singhal(jugshaurya)
  Date : 24-08-2022 T13
*/

// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int						 long long
#define pqmax					 priority_queue<int>
#define pqmin					 priority_queue<int,vector<int>,greater<int> >
#define setbits(x)			__builtin_popcountll(x)
#define zrobits(x)			__builtin_ctzll(x)
#define mod						 1000000007 // 1e9+7
#define inf						 1e18
#define ps(x,y)				 fixed<<setprecision(y)<<x
#define mk(arr,n,type)	type *arr=new type[n];
#define endl						"\n"
#define IOS							ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(_x)					_x.begin(), _x.end()
#define sz(_x)					int(_x.size())
mt19937								 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

inline void fastIO(){
  IOS
  // for Google kickstart comment next line
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}

// clang-format on
string a, b, c;
int n, m, o;

int dp[101][101][101];

int rec(int i, int j, int k) {
  if (i == n or j == m or k == o) return 0;

  if(dp[i][j][k] != -1) return dp[i][j][k];

  int ans = 0;
  if(a[i] == b[j] and b[j] == c[k]) ans = max(ans, 1 + rec(i + 1, j + 1, k + 1));
	else{
      ans = max(ans, rec(i + 1, j, k));
      ans = max(ans, rec(i, j + 1, k));
      ans = max(ans, rec(i, j, k + 1));
    }

  return dp[i][j][k] = ans;
}

void printSet(int i, int j, int k){
 if (i == n or j == m or k == o) return;

  int ans = 0;
  if(a[i] == b[j] and b[j] == c[k]) {
    cout<<a[i]<<"";
    printSet(i + 1, j + 1, k + 1);

  }	else {
      int opt1 = rec(i + 1, j, k);
      int opt2 = rec(i, j + 1, k);
      int opt3 = rec(i, j, k + 1);

      if(opt1 >= opt2 and opt1 >= opt3){
        printSet(i + 1, j, k);
      }else if(opt2 >= opt1 and opt2 >= opt3){
        printSet(i, j + 1, k);
      }else if(opt3 >= opt1 and opt3 >= opt2) {
        printSet(i, j, k + 1);
      }else{
        assert("safasd");
      }
  }
}

void solve(int _t) {
  cin >> a >> b >> c;
  n = a.size();
  m = b.size();
  o = c.size();
  
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= o; k++) {
        dp[i][j][k] = -1;
      }
    }
  }

  // memset(dp, -1, sizeof(dp));

  cout << rec(0, 0, 0) << endl;

  printSet(0,0,0);
}

// clang-format off
signed main() {
  fastIO();
  int _t = 1; 
  // cin>>_t; for(int i=1;i<=_t;i++) 
  solve(_t);
  return 0;
}
