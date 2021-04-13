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

const ll INF = 1e18;
const ll M = 3 * 1e5 + 10, B = sqrt(M);
// バケット i は [i*B, (i+1)*B) の記録を持つ
// lazy[i] :=  バケットi の遅延を記録する
// update の単位元を10000とする
// i.e. lazy[i] == 10000 のときは消化時に何も伝播させないという遅延を与えるとみなして例外処理を行う
// sum[i] := パケットi の総和
vll lazy(B, 0), sum(B, 0), a(M, 0);
ll unit = 10000;
 
// a_s, ..., a_t に x を加算する
void update(int s, int t, int x){
    // s の属するバケット, t の属するバケット
    int st = s / B, gt = t / B;

    // st や gt に遅延を消化しておく
    // 遅延はパケットごとに考えるから, 遅延が存在⇔パケット内は全て等しい値に更新されている
    // したがって sum[st] = B * lazy[st] が成立
    if (lazy[st] != unit){
        for (int i = st * B; i < (st + 1) * B; i++) a[i] = lazy[st];
        sum[st] = B * lazy[st];
        lazy[st] = unit;
    }
    if (lazy[gt] != unit){
        for (int i = gt * B; i < (gt + 1) * B; i++) a[i] = lazy[gt];
        sum[gt] = B * lazy[gt];
        lazy[gt] = unit;
    }
    
    //... || ... s ... t ... || ...
    //更新が同一パケット内で済むなら直接更新しても間に合う
    if (st == gt){
        for (int i = s; i <= t; i++) a[i] = x;
        sum[st] = 0;
        for (int i = st * B; i < (st + 1) * B; i++) sum[st] += a[i];
    }

    //... s ... || (被覆されるパケット) || ... t ...
    else{
        //端が属するパケット内は直接更新
        for (int i = s; i < (st + 1) * B; i++) a[i] = x;
        sum[st] = 0;
        for (int i = st * B; i < (st + 1) * B; i++) sum[st] += a[i];
 
        for (int i = gt * B; i <= t; i++) a[i] = x;
        sum[gt] = 0;
        for (int i = gt * B; i < (gt + 1) * B; i++) sum[gt] += a[i];

        //区間に被覆されるパケットについては更新を遅延に残す
        //区間内はすべて x に更新されるのでパケット内の総和は B * x になる
        for (int i = st + 1; i < gt; i++){
            lazy[i] = x;
            sum[i] = B * x;
        }
    }
}
 
// a_s,...,a_t の sum を返す
ll getsum(int s, int t){
    ll ret = 0;
    int st = s / B, gt = t / B;

    // まずは端の遅延を消化
    if (lazy[st] != unit){
        for (int i = st * B; i < (st + 1) * B; i++) a[i] = lazy[st];
        sum[st] = B * lazy[st];
        lazy[st] = unit;
    }
    if (lazy[gt] != unit){
        for (int i = gt * B; i < (gt + 1) * B; i++) a[i] = lazy[gt];
        sum[gt] = B * lazy[gt];
        lazy[gt] = unit;
    }

    //... || ... s ... t ... || ...
    //直接計算
    if (st == gt){
        for (int i = s; i <= t; i++) ret += a[i];
    }
    //... s ... || (被覆されるパケット)  || ... t ...
    else{
        //端が属するパケット内は直接計算
        for (int i = s; i < (st + 1) * B; i++) ret += a[i];
        for (int i = gt * B; i <= t; i++) ret += a[i];

        //被覆されるパケットはパケット単位で調査する
        for (int i = st + 1; i < gt; i++){
            //遅延が存在しない場合, update() によって sum[i] に和が保持されている
            if (lazy[i] == unit) ret += sum[i];
            //遅延が存在するならばパケット内は全て等しい値 lazy[i] になっている
            else ret += B * lazy[i];
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
        if(type == 1){
            int s, t, x;
            cin >> s >> t >> x;
            update(s, t, x);
        }
        else{
            int s, t;
            cin >> s >> t;
            cout << getsum(s, t) << endl;
        }
    }
    return 0;
}
