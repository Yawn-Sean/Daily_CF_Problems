#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;
i64 inf = 1e18;

struct Info {
    // mn1, mx1 for (a[i] + i)
    // mn2, mx2 for (a[i] - i)
    i64 mn1 = inf;
    i64 mn2 = inf;
    i64 mx1 = -inf;
    i64 mx2 = -inf;
    i64 ans = 0;
};

Info operator+(Info a, Info b) {
    Info c;
    c.mn1 = min(a.mn1, b.mn1);
    c.mn2 = min(a.mn2, b.mn2);
    c.mx1 = max(a.mx1, b.mx1);
    c.mx2 = max(a.mx2, b.mx2);
    c.ans = max(a.ans, b.ans);
    c.ans = max(c.ans, a.mx1 - b.mn1);
    c.ans = max(c.ans, b.mx2 - a.mn2);
    return c;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<Info> init(n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            init[i] = {a[i] + i, a[i] - i, a[i] + i, a[i] - i, 0};
        }

        SegmentTree<Info> seg(init);
        cout << seg.rangeQuery(0, n).ans << endl;
        while (q--) {
            int p, x;
            cin >> p >> x;
            --p;
            seg.modify(p, {x + p, x - p, x + p, x - p, 0});
            cout << seg.rangeQuery(0, n).ans << endl;
        }
    }

    return 0;
}
