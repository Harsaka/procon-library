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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<P> p;
  ll a, b;
  REP(i, m){
    cin >> a >> b;
    a--;
    b--;
    p.push_back(P(a, b));
  }
  UnionFind uf(2 * n);

  int di = 1;

  REP(i, m){
    a = p[i].first, b = p[i].second;
    if(uf.find(a, b)){
      di = 0;
      break;
    }
    uf.unite(a, b + n);
    uf.unite(b, a + n);
  }
  ll ans;
  if(di){
    ll col1 = 0, col2;
    a = p[0].first;
    REP(i, n){
      if(uf.find(a, i)) col1++;
    }
    col2 = n - col1;
    ans = col1 * col2 - m;
  }
  else{
    ans = n * (n - 1) / 2 - m;
  }
  cout << ans << endl;

  return 0;
}
