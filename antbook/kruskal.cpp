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

struct edge{
  	ll from, to, cost;
};

bool comp(const edge& e1, const edge& e2){
  	return e1.cost < e2.cost;
}

int main(){
  	cin.tie(0);
  	ios::sync_with_stdio(false);

  	ll n, m;
  	cin >> n >> m;
  	ll a, b, c;
  	vector<edge> es;
  	REP(i, m){
    	cin >> a >> b >> c;
    	a--;
    	b--;
    	es.push_back((edge){a, b, c});
  	}
  	sort(es.begin(), es.end(), comp);
  	ll res = 0;
  	UnionFind uf(n);
  	for(auto e : es){
    	if(!uf.find(e.from, e.to)){
      		uf.unite(e.from, e.to);
      		res += e.cost;
    	}
  	}
  	cout << res << endl;
  	return 0;
}
