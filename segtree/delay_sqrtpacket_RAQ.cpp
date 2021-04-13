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

int B = 400;
// バケット i は [i*B, (i+1)*B) の記録を持つ
// lazy[i] :=  バケットi の遅延を記録する
// 0 ... 加算の単位元(laze[i] == 0 ⇔ 消化しても伝播しない
//今回は本当に単位元なので例外処理的な扱いをしなくていい
vector<int> lazy(B, 0), a(100000, 0);
 
// a_s, ..., a_t に x を加算する
void add(int s, int t, int x)
{
    // s の属するバケット, t の属するバケット
    int st = s / B, gt = t / B;

    //... || ... s ... t ... || ...
    //更新が同一パケット内で済むなら直接更新しても間に合う
    if (st == gt){
        for (int i = s; i <= t; i++) a[i] += x;
    }

    //... s ... || (被覆されるパケット) || ... t ...
    else{
        //端が属するパケット内は直接更新
        for (int i = s; i < (st + 1) * B; i++) a[i] += x;
 
        for (int i = gt * B; i <= t; i++) a[i] += x;

        //区間に被覆されるパケットについては加算を遅延に残す
        //addは結合法則を満たすのでlazyには消化されるまで何回も遅延を上乗せできる
        //該当パケットが参照されたときにlazy[i]を加算すればよい
        for (int i = st + 1; i < gt; i++){
            lazy[i] += x;
        }
    }
}
 
// a_s を返す
int find(int s){
    int st = s / B;

    // s が属するパケットの遅延を消化
    for (int i = st * B; i < (st + 1) * B; i++) a[i] += lazy[st];
    lazy[st] = 0;
    return a[s];
}
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    REP(i, q){
        int type;
        cin >> type;
        if(type == 0){
            int s, t, x;
            cin >> s >> t >> x;
            add(s, t, x);
        }
        else{
            int s;
            cin >> s;
            cout << find(s) << endl;
        }
    }
    return 0;
}
