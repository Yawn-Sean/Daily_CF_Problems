#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int64 INF = 2e18;

struct segtree {
    int n;
    vector<int64> t;
    segtree(int n) : n(n) {
        t.resize(4 * n, 0);
    }
    
    void add(int v, int l, int r, int pos, int64 val) {
        if (l + 1 == r) {
            t[v] += val;
            return;
        }
        int m = (l + r) >> 1;
        if (pos < m) {
            add(v * 2 + 1, l, m, pos, val);
        } else {
            add(v * 2 + 2, m, r, pos, val);
        }
        t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    }
    
    int64 query(int v, int l, int r, int L, int R) {
        if (L >= R) return -INF;
        if (l == L && r == R) 
            return t[v];
        int m = (l + r) >> 1;
        int64 r1 = query(v * 2 + 1, l, m, L, min(m, R));
        int64 r2 = query(v * 2 + 2, m, r, max(m, L), R);
        t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
        return max(r1, r2);
    }
    
    void add(int pos, int64 val) {
        return add(0, 0, n, pos, val);
    }
    
    int64 query(int l, int r) {
        return query(0, 0, n, l, r);
    }
};

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int64> j(n);
    for (auto& x : j) {
        scanf("%lld", &x);
    }
    ranges::sort(j);
    k -= 1;
    segtree sg(k);
    for (int i = 0, l, r, x; i < m; i++) {
        scanf("%d %d %d", &l, &r, &x);
        l -= 1;
        r -= 1;
        if (l) sg.add(l - 1, x);
        if (r < k) sg.add(r, -x);
        int64 mx = sg.query(0, k);
        printf("%d\n", n - (ranges::lower_bound(j, mx) - j.begin()));
    }
    return 0;
}

