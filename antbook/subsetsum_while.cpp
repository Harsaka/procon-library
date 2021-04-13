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
  ll a[n];
  REP(i, n) cin >> a[i];
  vector<ll> sum;
  sum.push_back(0);
  ll bin = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < bin; j++){
      sum.pb(sum[j] + a[i]);
    }
    bin *= 2;
  }
  REP(i, sum.size()){
    if(sum[i] == k){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
