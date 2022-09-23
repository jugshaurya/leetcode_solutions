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
  int w, h, t;
  cin >> w >> h >> t;

  set<int> posx, posy;

  int x, y;
  for (int i = 0; i < t; i++) {
    cin >> x >> y;

    posx.insert(x);
    posy.insert(y);
  }

  // adding boundries
  posx.insert(0);
  posx.insert(w + 1);
  posy.insert(0);
  posy.insert(h + 1);

  int maxx = INT_MIN;
  int maxy = INT_MIN;

  int lastx = *posx.begin();
  for (auto x : posx) maxx = max(maxx, x - lastx), lastx = x;

  int lasty = *posy.begin();
  for (auto y : posy) maxy = max(maxy, y - lasty), lasty = y;

  cout << (maxx - 1) * (maxy - 1) << endl;
}

// clang-format off
signed main() {
  fastIO();
  int _t = 1; 
  cin>>_t; for(int i=1;i<=_t;i++) 
  solve(_t);
  return 0;
}
