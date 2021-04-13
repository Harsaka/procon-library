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

  ll n;
  cin >> n;
  int a[n];
  map<int, ll> num, mp;
  REP(i, n){
    cin >> a[i];
    num[a[i]]++;
  }

  ll len = 0, l = 0, r = 0, res = n + 1, rec;
  REP(i, num.size()){
    if(num[i] != 0) len++;
  }

  while(1){
    while(r < n){
      if(rec == len) break;
      mp[r]++;
      rec = 0;
      REP(i, mp.size()){
        if(mp[i] != 0) rec++;
      }
      r++;
    }
    if(rec < len) break;
    res = min(res, r - l);
    mp[l]--;
    rec = 0;
    REP(i, mp.size()){
      if(mp[i] != 0) rec++;
    }
    l++;
  }
  if(res > n){
    cout << -1 << endl;
    return 0;
  }
  cout << res << endl;
  return 0;
}
