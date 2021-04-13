#include "bits/stdc++.h"
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  /*
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  REP(i, n) cin >> c[i];
  REP(i, n) cin >> d[i];

  */
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  vector<int> ab, cd;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ab.push_back(a[i] + b[j]);
      cd.push_back(c[i] + d[j]);
    }
  }
  int len = ab.size(), ans = 0;
  sort(cd.begin(), cd.end());
  for(int i = 0; i < len; i++){
    ans += upper_bound(cd.begin(), cd.end(), -ab[i]) - lower_bound(cd.begin(), cd.end(), -ab[i]);
  }
  cout << ans << endl;
  return 0;
}
