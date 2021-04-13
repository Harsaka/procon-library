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
ll inf = 1e9;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  char c[n][m];
  ll d[n][m], sx, sy, gx, gy;
  REP(i, n){
    REP(j, m){
      cin >> c[i][j];
      if(c[i][j] == "S"){
        sx = j;
        sy = i;
      }
      if(c[i][j] == "G"){
        gx = j;
        gy = i;
      }
      d[i][j] = inf;
    }
  }

  queue<P> p;
  p.push(P(sx, sy));
  d[sx][sy] = 0;
  while(1){
    
  }
  

  return 0;
}
