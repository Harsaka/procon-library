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

// retun n の約数の集合
vector<ll> yakusuu(ll n){
      vector<ll> y;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0) y.push_back(i);
    }
      ll len = y.size();
      REP(i, len){
        if(y[i] == n / y[i]) continue;
        y.push_back(n / y[i]);
    }
    return y;
}

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vll y = yakusuu(n);
    VSORT(y);
    for(auto x : y){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}