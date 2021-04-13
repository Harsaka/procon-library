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

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

//zaki_FenwickTree

template <typename T>

class FenwickTree
{
    int n;
    std::vector<T> bit;

  public:
    FenwickTree(int _n) : n(_n), bit(_n, 0) {}

    void add(int pos, const T &w)
    {
        assert(0 <= pos && pos < n);
        for (int i = pos; i < n; i |= i + 1)
            bit[i] += w;
    }
    // v[0] + ... + v[pos-1]
    T sum(int pos)
    {
        assert(0 <= pos && pos <= n);
        T res = 0;
        for (int i = pos - 1; i >= 0; i = (i & (i + 1)) - 1)
        {
            res += bit[i];
        }
        return res;
    }
    T sum(int l, int r)
    {
        assert(0 <= l && l <= r && r <= n);
        return sum(r) + (-sum(l));
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
    }
    FenwickTree<int> ft(n + 1);
    ll ans = 0;
    REP(i, n){
        ans += ft.sum(a[i] + 1, n + 1);
        ft.add(a[i], 1);
    }
    cout << ans << endl;
}