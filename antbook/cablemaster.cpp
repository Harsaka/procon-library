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

  int n, k;
  cin >> n >> k;
  double a[n];
  REP(i, n) cin >> a[i];
  SORT(a, n);

  double lb = 0, ub = a[n - 1];

  while(ub - lb > 1e-08){
    double mid = (lb + ub) / 2;
    int rec = 0;
    REP(i, n){
      rec += a[i] / mid;
    }
    if(rec >= k) lb = mid;
    else ub = mid;
  }
  lb = floor(100 * lb) / 100;
  printf("%.2lf\n", lb);
  return 0;
}
