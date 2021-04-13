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

bool isin(int m, int end){
  if(m >= 0 && m < end) return true;
  else return false;
}

void dfs(int x, int y, int w, int h, char *c){
  c[w * y + x] = '.';
  int nx, ny;
  for(int dx = -1; dx <= 1; dx++){
    for(int dy = -1; dy <= 1; dy++){
      nx = x + dx;
      ny = y + dy;
      if(isin(nx, w) && isin(ny, h) && c[w * ny + nx] == 'W') dfs(nx, ny, w, h, c);
    }
  }
  return;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int w, h;
  cin >> w >> h;

  char c[h * w];
  REP(i, h){
    REP(j, w) cin >> c[w * i + j];
  }

  ll ans = 0;
  REP(i, h){
    REP(j, w){
      if(c[w * i + j] == 'W'){
        dfs(j, i, w, h, c);
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
