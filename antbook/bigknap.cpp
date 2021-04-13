#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = 1e18;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll n, W;
    cin >> n >> W;

    vll w(n), v(n);
    REP(i, n) cin >> v[i] >> w[i];
    ll mid = n / 2;
    vector<P> first_half((1LL << mid)); // first_half[i] : 前半の全列挙 (ww, vv)
    REP(i, 1LL << mid) {
        ll fw = 0, fv = 0;
        REP(j, mid) {
            if (i >> j & 1) {
                fw += w[j];
                fv += v[j];
            }
        }
        first_half[i] = P(fw, fv);
    }
    VSORT(first_half);
    //ww  vv
    //10  30
    //20  20
    //みたいなのがあるとき，(20, 20)より(10, 30)の方が良いので潰す
    REP(i, (1LL << mid) - 1) {
        if (first_half[i + 1].second < first_half[i].second) first_half[i + 1] = first_half[i];
    }
    ll res = 0;
    REP(i, 1LL << (n - mid)) {
        ll lw = 0, lv = 0;
        REP(j, n - mid) {
            if ((i >> j) & 1) {
                lw += w[mid + j];
                lv += v[mid + j];
            }
        }
        // 重さ和 W - lw 以内で価値和最大のものを前半の全列挙から二分探索
        if (lw <= W) {
            ll rr = first_half[upper_bound(ALL(first_half), P(W - lw, INF)) - first_half.begin() - 1].second;
            chmax(res, lv + rr);
        }
    }
    cout << res << endl;
    return 0;
}