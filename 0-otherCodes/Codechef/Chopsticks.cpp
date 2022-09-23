/*
  Author : Shaurya Singhal(jugshaurya)
  Date : 23-09-2022 T13
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

void solve(int _t) {
  int n, d;
  cin >> n >> d;

  int sticks[n];
  for (int i = 0; i < n; i++) {
    cin >> sticks[i];
  }

  sort(sticks, sticks + n);

  int i = 1;
  int ans = 0;
  while (i < n) {
    if (sticks[i] - sticks[i - 1] <= d) ans++, i += 2;
    else i++;
  }

  cout << ans << endl;
}

// clang-format off
signed main() {
  fastIO();
  int _t = 1; 
  // cin>>_t; for(int i=1;i<=_t;i++) 
  solve(_t);
  return 0;
}
