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

  ll n, s;
  cin >> n >> s;
  ll a[n];
  REP(i, n) cin >> a[i];

  ll l = 0, r = 0, res = n + 1, sum = 0;

  while(1){
    while(r < n && sum < s){
      sum += a[r];
      r++;
    }
    if(sum < s) break;
    
    res = min(res, r - l);
    sum -= a[l];
    l++;
  }

  if(res > n){
    cout << 0 << endl;
    return 0;
  }
  cout << res << endl;

  return 0;
}
