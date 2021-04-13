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


int B = 320;
// バケット i は [i*B, (i+1)*B) の記録を持つ
// lazy[i] :=  バケットi の遅延を記録する
// 遅延が-1 ... 制約よりそんなことは発生しないことを利用して, これを遅延の単位元とできる
// i.e. lazy[i] == -1 def 消化時に何も伝播させないという遅延を与えるとみなす
vector<int> lazy(B, -1), a(100000, (1LL << 31) - 1);
 
// a_s, ..., a_t を x に変更する
void update(int s, int t, int x)
{
    // s の属するバケット, t の属するバケット
    int st = s / B, gt = t / B;

    // st や gt に遅延が存在するとき更新前に消化しておく
    // 遅延はパケットごとに考えるから, 遅延が存在⇔パケット内は全て等しい値で更新されている
    // 区間に被覆されるパケットについてはこのあと新しい値へ更新されるので消化しなくてOK
    if (lazy[st] != -1){
        for (int i = st * B; i < (st + 1) * B; i++) a[i] = lazy[st];
        lazy[st] = -1;
    }
    if (lazy[gt] != -1){
        for (int i = gt * B; i < (gt + 1) * B; i++) a[i] = lazy[gt];
        lazy[gt] = -1;
    }
    //... || ... s ... t ... || ...
    //更新が同一パケット内で済むなら直接更新しても間に合う
    if (st == gt){
        for (int i = s; i <= t; i++) a[i] = x;
    }

    //... s ... || (被覆されるパケット) || ... t ...
    else{
        //端が属するパケット内は直接更新
        for (int i = s; i < (st + 1) * B; i++) a[i] = x;
        for (int i = gt * B; i <= t; i++) a[i] = x;

        //区間に被覆されるパケットについては更新を遅延に残す
        for (int i = st + 1; i < gt; i++){
            lazy[i] = x;
        }
    }
}
 
// a_i を返す
int find(int s){
    int st = s / B;
    //遅延を処理する
    if (lazy[st] != -1){
        for (int i = st * B; i < (st + 1) * B; i++) a[i] = lazy[st];
        lazy[st] = -1;
    }
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
            update(s, t, x);
        }
        else{
            int s;
            cin >> s;
            cout << find(s) << endl;
        }
    }
    return 0;
}