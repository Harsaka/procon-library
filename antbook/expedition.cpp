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

  ll n, l, p;
  cin >> n >> l >> p;
  ll a, b;
  vector<P> gass;
  REP(i, n){
    cin >> a >> b;
    gass.push_back(P(a, b));
  }
  VSORT(gass);
  gass.push_back(P(l, 0));
  priority_queue<int> que;
  ll tank = p, pos = 0, ans = 0;
  REP(i, n + 1){
    ll dist = gass[i].first - pos;
    while(tank - dist < 0){
      if(que.empty()){
        cout << -1 << endl;
        return 0;
      }
      tank += que.top();
      que.pop();
      ans++;
    }
    tank -= dist;
    pos = gass[i].first;
    que.push(gass[i].second);
  }

  cout << ans << endl;
  return 0;
}
