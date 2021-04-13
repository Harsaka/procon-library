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

bool dfs(ll i, ll sum, const ll n, const ll k, ll *a){
  if(i == n) return sum == k;
  if(dfs(i + 1, sum, n, k, a)) return true;
  if(dfs(i + 1, sum + a[i], n, k, a)) return true;

  return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  ll a[n];
  REP(i, n) cin >> a[i];

  if(dfs(0, 0, n, k, a)) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
