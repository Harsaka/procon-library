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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n);
  REP(i, n){
    if(s[i] == 'B') a[i] = 1;
    else a[i] = 0;
  }
  int K = 1, M = n, possible = 0;
  for(int k = 1; k <= n; k++){//反転範囲kを固定
    ll inv[n] = {};
    
    ll sum = 0, res = 0; //sum:今みてる地点に反転が行われた回数
    for(int i = 0; i + k <= n; i++){
      if((a[i] + sum) % 2){
        res++;
        inv[i] = 1; //iを始点に反転を実行
      }
      sum += inv[i];
      if(i - k + 1 >= 0) sum -= inv[i - k + 1]; //反転範囲はkなのでk-1番目に反転されてたら次回からその影響がなくなる
    }
    for(int i = n - k + 1; i < n; i++){ //反転が実行できない範囲で向きが合ってるかどうかを調べる
      if((a[i] + sum) % 2){
        res = -1;
        break;
      }
      if(i - k + 1 >= 0) sum -= inv[i - k + 1];
    }
    if(res >= 0 && res < M){
      possible = 1;
      M = res;
      K = k;
    }
  }
  if(!possible) cout << -1 << endl;
  else cout << K << " " << M << endl;
  return 0;
}
