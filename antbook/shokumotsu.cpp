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

//zaki_UnionFind
class UnionFind
{
    std::vector<int> data;

  public:
    UnionFind(int size) : data(size, -1) {}
    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (data[y] < data[x])
                std::swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool find(int x, int y)
    {
        return root(x) == root(y);
    }
    int root(int x)
    {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x)
    {
        return -data[root(x)];
    }
};

bool isin(ll x, ll n){
  return (x >= 0 && x < n);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  UnionFind uf(3 * n);
  ll t, x, y, ans = 0;
  REP(i, k){
    cin >> t >> x >> y;
    x--;
    y--;
    if(!isin(x, n) || !isin(y, n)){
      ans++;
      continue;
    }
    if(t == 1){
      if(uf.find(x, y + n) || uf.find(x, y + 2 * n)){
        ans++;
        continue;
      }
      uf.unite(x, y);
      uf.unite(x + n, y + n);
      uf.unite(x + 2 * n, y + 2 * n);
    }
    if(t == 2){
      if(uf.find(x, y) || uf.find(x, y + 2 * n)){
        ans++;
        continue;
      }
      uf.unite(x, y + n);
      uf.unite(x + n, y + 2 * n);
      uf.unite(x + 2 * n, y);
    }
  }
  cout << ans << endl;
  return 0;
}
