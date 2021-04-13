#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)

ll mod = 1e9 + 7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  ll x[n];
  REP(i, n) cin >> x[i];
  SORT(x, n);
  ll lb = 0, ub = x[n - 1] - x[0];

  while(ub - lb > 1){
    ll mid = (lb + ub) / 2;
    ll l = 0, r = 1, cnt = 1;
    while(1){
      if(r == n) break;
      if(x[r] - x[l] >= mid){
        l = r;
        cnt++;
      }
      r++;
    }
    if(cnt >= m) lb = mid;
    else ub = mid;
  }
  cout << lb << endl;
  return 0;
}
