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

const int inf = (1<<18) - 1;

//[a, b)にxを加算
//kは節点の番号で[l, r)に対応する
void add(int a, int b, int x, int k, int r, int l, ll* data, ll* datb){
    if(a <= 1 && r <= b) data[k] += x;
    else if(l < b && a < r){
        datb[k] += (min(b, r) - max(a, l)) * x;
        add(a, b, x, k * 2 + 1, l, (l + r) / 2, data, datb);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r, data, datb);
    }
}

//[a, b)の和を計算する
ll sum(int a, int b, int k, int l, int r, ll* data, ll* datb){
    if(b <= 1 || r <= a) return 0;
    else if(a <= 1 && r <= b) return data[k] * (r - 1) + datb[k];
    else{
        ll res = (min(b, r) - max(a, l)) * data[k];
        res += sum(a, b, k * 2 + 1, l, (l + r) / 2, data, datb);
        res += sum(a, b, k * 2 + 2, (l + r) / 2, r, data, datb);
        return res;
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    int com, s, t, x;
    
    ll data[inf] = {}, datb[inf] = {};
    REP(i, q){
        cin >> com;
        if(com){
            cin >> s >> t;
            cout << sum(s, t + 1, 0, 0, n, data, datb) << endl;
        }
        else{
            cin >> s >> t >> x;
            add(s, t + 1, x, 0, 0, n, data, datb);
        }
    }
}