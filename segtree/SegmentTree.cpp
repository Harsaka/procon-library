#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

//zaki_SegmentTree

const int INF = 2147483647;
//RMQ
class SegmentTree
{
    int n;
    std::vector<int> node;

  public:
    // v を基に初期化
    SegmentTree(const std::vector<int> &v)
    {
        // n は v.size() 以上の最小の2冪
        n = 1;
        while (n < int(v.size()))
            n *= 2;
        node.resize(2 * n - 1, INF);

        // i の子 -> 2*i+1, 2*i+2 , 親 -> (i-1)/2
        for (int i = 0; i < int(v.size()); i++)
            node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }
    // x 番目を val に更新
    void update(int x, int val)
    {
        x += n - 1;
        node[x] = val;
        while (x > 0)
        {
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }
    // v[x] を M::op(v[x], val) に更新
    void add(int x, int val)
    {
        x += n - 1;
        node[x] = min(node[x], val);
        while (x > 0)
        {
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }
    // [a, b) の op
    // k := 今居るノード
    int query(int a, int b, int k = 0, int l = 0, int r = -1)
    {
        if (r < 0)
            r = n;
        if (r <= a || b <= l)
            return INF;
        if (a <= l && r <= b)
            return node[k];

        int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};

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