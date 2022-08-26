/* https://www.codingninjas.com/codestudio/problems/colorful-knapsack_630415 */

/*
  Author : Shaurya Singhal(jugshaurya)
  Date : 24-08-2022 T00
*/

#include<bits/stdc++.h>
using namespace std;

int n, m, W;
vector<pair<int, int>> obj;
int done[101][10001];
int ans;

void rec(int i , int w){

  if(i == n) {
    ans = min(ans, w);
    return; 
  }

  if(done[i][w] != -1) return;

  int j = i + 1;
  while(j < n and obj[j].first == obj[j - 1].first){
    j++;
  }

  for (int k = i; k < j; k++){
      if(w - obj[k].second >= 0) rec(j, w - obj[k].second);
  }

  done[i][w] = 1;
}

int colorfulKnapsack(int w[], int c[], int a, int b, int x){
    n = a;
    m = b;
    W = x;
    ans = INT_MAX;
  obj.resize(n, {-1,-1});

  set<int> s;
  for(int i=0;i<n;i++){
    obj[i].second = w[i];
  }

  for(int i=0;i<n;i++){
    obj[i].first = c[i];
      s.insert(obj[i].first);
  }

  if(s.size() < m){
    return -1;
  }
  sort(obj.begin(), obj.end());
  memset(done, -1, sizeof(done));
  rec(0, W);

    if(ans < 0 or ans == INT_MAX){
    return -1;
  }
    
    return ans;
}

// Problem Statemnt

/*
You are given N stones, labeled from 1 to N. The i-th stone has the weight W[i]. There are M colors, labeled by integers from 1 to M. The i-th stone has the color C[i] (of course, an integer between 1 to M, inclusive). You want to fill a Knapsack with these stones. The Knapsack can hold a total weight of X. You want to select exactly M stones; one of each color. The sum of the weights of the stones must not exceed X. Since you paid a premium for a Knapsack with capacity X (as opposed to a Knapsack with a lower capacity), you want to fill the Knapsack as much as possible.
Write a program that takes all the above values as input and calculates the best way to fill the Knapsack – that is, the way that minimizes the unused capacity. Output this unused capacity.

Input
The first line of input contains the integer T, the number of test cases. Then follows the description of T test cases. The first line of each test case contains three integers, N, M and X, separated by singlespace. The next line contains N integers, W[1], W[2], W[3] … W[N], separated by single space. The next line contains N integers C[1], C[2], C[3] … C[N], separated by single space.

Output
An optimal way of filling the Knapsack minimizes unused capacity. There may be several optimal ways of filling the Knapsack. Output the unused capacity of the Knapsack (a single integer on a line by itself) for an optimal way. If there is no way to fill the Knapsack, output -1. Output T lines, one for each test case.

Constraints

1 ≤ T ≤ 10
1 ≤ M ≤ 100
M ≤ N ≤ 100
1 ≤ W[i] ≤ 100
1 ≤ C[i] ≤ M
1 ≤ X ≤ 10000

Sample Input
4
9 3 10
2 3 4 2 3 4 2 3 4
1 1 1 2 2 2 3 3 3
9 3 10
1 3 5 1 3 5 1 3 5
1 1 1 2 2 2 3 3 3
3 3 10
3 4 4
1 2 3
3 3 10
3 3 3
1 2 1

Sample Output
0
1
-1
-1
*/
