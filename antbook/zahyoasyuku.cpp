#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

ll mod = 1e9 + 7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll w, h, n;
  cin >> w >> h >> n;

  vll x1(n), x2(n), y1(n), y2(n);
  REP(i, n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

  
  bool isin = [&] (int a, int bound){
    if(a >= 1 && a <= bound) return true;
    else return false;
  };

  auto compress = [&] (int *s, int *t, int w){
    vll xs; //圧縮後の候補列
    for(int i = 0; i < n; i++){
      for(int d = -1; d <= 1; d++){
        int tx1 = s[i] + d, tx2 = t[i] + d;
        if(isin(tx1, w)) xs.push_back(tx1);
        if(isin(tx2, w)) xs.push_back(tx2);
      }
    }
    VSORT(xs);
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    REP(i, n){
      s[i] = find(xs.begin(), xs.end(), s[i]) - xs.begin();
      t[i] = find(xs.begin(), xs.end(), t[i]) - xs.begin();
    }
    return xs.size();
  };

  w = compress(x1, x2, w);
  h = compress(y1, y2, h);

  

  return 0;
}
