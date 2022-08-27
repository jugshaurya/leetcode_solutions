/*
  Author : Shaurya Singhal(jugshaurya)
  Date : 27-08-2022 T11
*/

// clang-format off
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma comment(linker, "/stack:200000000")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int						 long long
#define pqmax					 priority_queue<int>
#define pqmin					 priority_queue<int,vector<int>,greater<int> >
#define setbits(x)			__builtin_popcountll(x)
#define zrobits(x)			__builtin_ctzll(x)
#define ps(x,y)				 fixed<<setprecision(y)<<x
#define mk(arr,n,type)	type *arr=new type[n];
#define endl						"\n"
#define all(_x)				 _x.begin(), _x.end()
#define m(_x)					 int(_x.size())
#define FASTIO					ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define google(_x)			cout << "Case #" << _x << ": "
mt19937								 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int MOD = 1e9+7; const int INF = 1e18;

void IO(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


// Binary Exponentitation
int powr(int a,int b){int res=1;while(b){if(b&1)res*=a;a*=a;b>>=1;}return res;}
// Binary Exponentitation with mod
int powrMod(int a,int b,int m){int res=1;a%=m;while(b){if(b&1)res=res*a%m;a=a*a%m;b>>=1;}return res;}

// clang-format on
void pre() {}

// dp(i, p) =  b[i][0] + dp(i+1, p-1), b[i][0] + b[i][1] + dp(i+1, p-2), ...... dp(i+1, p-x) ; x < min(p, k)
// dp(i, p, j) =  max(b[i][j] + dp(i, p - 1, j + 1), dp(i + 1, p, 0));
// TC : (NK P)


int n, k;
int beauty[51][31];
int dp[51][31];

int rec(int i, int p){
	if(i == n){
		return 0;
	}
    
	if(dp[i][p] != -1) return dp[i][p];

	// not take from current stack
	int ans = rec(i + 1, p);
	// try to take x plates from curret stack
	int sum = 0;
	for (int x = 1; x <= min(k, p); x++){
		sum += beauty[i][x-1];
		
		ans = max(ans, sum + rec(i + 1, p - x));
	}

	return dp[i][p] = ans;	
}

void solve() {
	int p;
  cin >> n >> k >> p;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> beauty[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));
	cout << rec(0, p) << endl;
}

// clang-format off
signed main() {
	FASTIO;
	IO();
	pre();
	int _t; cin>>_t; for(int i=1;i<=_t;i++)
	google(i), 
	solve();
	return 0;
}

