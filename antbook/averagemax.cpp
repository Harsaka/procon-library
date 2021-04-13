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

  ll n, k;
  cin >> n >> k;
  ll w[n], v[n];
  REP(i, n) cin >> w[i] >> v[i];

  double lb = 0, ub = 1e10;
  double y[n];
  while(ub - lb > 1e-6){
    double mid = (lb + ub) / 2;
    REP(i, n) y[i] = v[i] - mid * w[i];
    SORT(y, n);
    double sum = 0;
    REP(i, k) sum += y[n - 1 - i];
    if(sum >= 0) lb = mid;
    else ub = mid;
  }
  cout << lb << endl;
  return 0;
}