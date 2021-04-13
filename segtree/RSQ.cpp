#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)


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
    int n, q;
    cin >> n >> q;
    int com, x, y;
    FenwickTree<int> ft(1000000);
    REP(i, q){
        cin >> com >> x >> y;
        if(com) cout << ft.sum(x, y + 1) << endl;
        else ft.add(x, y);
    }
    return 0;
}