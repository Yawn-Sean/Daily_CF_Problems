#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
using TPI = pair<pair<int, int>, pair<int, int>>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

class SegmentTree {
public : 
    struct node {
        node (int l = 0, int r = 0, PII a = {0, 0}, PII b = {0, 0}) 
            : l(l), r(r), a(a), b(b) {}
        int l, r;
        PII a, b;
    };

    vector<node> tr;

    SegmentTree (int n) : tr(n + 10 << 2) {}

    TPI get(PII &a1, PII &a2, PII &b1, PII &b2) {
        PII none = {0, 0};
        if (a1.first) {
            if (a2.first && a2.first != a1.first) return {a1, a2};
            if (b1.first && b1.first != a1.first) return {a1, b1};
            if (b2.first && b2.first != a1.first) return {a1, b2};
            return {a1, none};
        }
        if (a2.first) {
            if (b1.first && b1.first != a2.first) return {a2, b1};
            if (b2.first && b2.first != a2.first) return {a2, b2};
            return {a2, none};
        }
        if (b1.first) {
            if (b2.first && b2.first != b1.first) return {b1, b2};
            return {b1, none};
        }
        if (b2.first) return {b2, none};
    }

    void push_up(int u) {
        node &root = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
        PII a1 = l.a, a2 = l.b, b1 = r.a, b2 = r.b;
        auto ans = get(a1, a2, b1, b2);
        root.a = ans.first, root.b = ans.second;
        return;
    }

    void buildTree(int u, int l, int r, vector<int> &arr) {
        tr[u].l = l, tr[u].r = r;
        if (l == r) tr[u].a = {arr[r], r};
        else {
            int mid = l + r >> 1;
            buildTree(u << 1, l, mid, arr);
            buildTree(u << 1 | 1, mid + 1, r, arr);
            push_up(u);
        }
        return;
    }

    TPI query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return {tr[u].a, tr[u].b};
        int mid = tr[u].l + tr[u].r >> 1;
        TPI left, right;
        if (l <= mid) left = query(u << 1, l, r);
        if (r > mid) right = query(u << 1 | 1, l, r);
        return get(left.first, left.second, right.first, right.second);
    }
};

void solve() { 
    int n, m; cin >> n >> m;
    vector<int> arr(n + 1);
    SegmentTree tr(n);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    tr.buildTree(1, 1, n, arr);
    while (m--) {
        int l, r, x; cin >> l >> r >> x;
        auto ans = tr.query(1, l, r);
        if (ans.first.first && ans.first.first != x) cout << ans.first.second << endl;
        else if (ans.second.first && ans.second.first != x) cout << ans.second.second << endl;
        else cout << -1 << endl;
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
