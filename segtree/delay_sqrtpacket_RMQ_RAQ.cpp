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
// mi[i] := パケットi の最小値
vector<int> lazy(B, 0), mi(B, 0), a(100000, 0);
 
// a_s, ..., a_t に x を加算する
void add(int s, int t, int x)
{
    // s の属するバケット, t の属するバケット
    int st = s / B, gt = t / B;

    // st や gt に遅延を消化しておく
    // 遅延はパケットごとに考えるから, 遅延が存在⇔パケット内は全て等しい値が加算されている
    // したがって mi[st] = mi[st] + lazy[st] が成立
    for (int i = st * B; i < (st + 1) * B; i++) a[i] += lazy[st];
    mi[st] += lazy[st];
    lazy[st] = 0;

    for (int i = gt * B; i < (gt + 1) * B; i++) a[i] += lazy[gt];
    mi[gt] += lazy[gt];
    lazy[gt] = 0;
    
    //... || ... s ... t ... || ...
    //更新が同一パケット内で済むなら直接更新しても間に合う
    if (st == gt){
        for (int i = s; i <= t; i++) a[i] += x;
        mi[st] = INT_MAX;
        for (int i = st * B; i < (st + 1) * B; i++) mi[st] = min(mi[st], a[i]);
    }

    //... s ... || (被覆されるパケット) || ... t ...
    else{
        //端が属するパケット内は直接更新
        for (int i = s; i < (st + 1) * B; i++) a[i] += x;
        mi[st] = INT_MAX;
        for (int i = st * B; i < (st + 1) * B; i++) mi[st] = min(mi[st], a[i]);
 
        for (int i = gt * B; i <= t; i++) a[i] += x;
        mi[gt] = INT_MAX;
        for (int i = gt * B; i < (gt + 1) * B; i++) mi[gt] = min(mi[gt], a[i]);

        //区間に被覆されるパケットについては加算を遅延に残す
        //addは結合法則を満たすのでlazyには消化されるまで何回も遅延を上乗せできる
        //mi[i]は該当パケットが参照されたときにlazy[i]を加算すればよい
        for (int i = st + 1; i < gt; i++){
            lazy[i] += x;
        }
    }
}
 
// a_s,...,a_t の min を返す
int find(int s, int t)
{
    int ret = INT_MAX;
    int st = s / B, gt = t / B;

    // まずは端の遅延を消化
    for (int i = st * B; i < (st + 1) * B; i++) a[i] += lazy[st];
    mi[st] += lazy[st];
    lazy[st] = 0;

    for (int i = gt * B; i < (gt + 1) * B; i++) a[i] += lazy[gt];
    mi[gt] += lazy[gt];
    lazy[gt] = 0;

    //... || ... s ... t ... || ...
    //直接計算
    if (st == gt){
        for (int i = s; i <= t; i++) ret = min(ret, a[i]);
    }
    //... s ... || (被覆されるパケット)  || ... t ...
    else{
        //端が属するパケット内は直接計算
        for (int i = s; i < (st + 1) * B; i++) ret = min(ret, a[i]);
        for (int i = gt * B; i <= t; i++) ret = min(ret, a[i]);

        //被覆されるパケットはパケット単位で調査する
        for (int i = st + 1; i < gt; i++){
            ret = min(ret, mi[i] + lazy[i]);
        }
    }
    return ret;
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
            int s, t;
            cin >> s >> t;
            cout << find(s, t) << endl;
        }
    }
    return 0;
}
