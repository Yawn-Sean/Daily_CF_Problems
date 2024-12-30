#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+q+1), b(n);
    multiset<int> h;
    vector<pair<int, ll>> queries(q);
    for (int i = 0; i < n; ++i) cin >> a[i], h.insert(b[i] = a[i]);
    int j = n;
    for (int i = 0; i < q; ++i) {
        ll x, y, z;
        cin >> x;
        if (x == 1) {
            cin >> y >> z; queries[i] = {y - 1, z};
            a[j++] = z;
        } else cin >> y, queries[i] = {-1, y};
    }
    a[j++] = -1;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    map<int, int> inv;
    int m = a.size();
    for (int i = 0; i < m; ++i) inv[a[i]] = i;

    vector<ll> sum(m), cnt(m);
    auto lb = [](int x) { return x & -x; };
    auto add = [&](vector<ll> &tree, int pos, ll v) { for (; pos < m; pos += lb(pos)) tree[pos] += v; };
    auto query = [&](vector<ll> &tree, int pos) { ll res = 0; for (; pos; pos -= lb(pos)) res += tree[pos]; return res; };

    for (int i = 0; i < n; ++i) add(sum, inv[b[i]], b[i]), add(cnt, inv[b[i]], 1);
    for (auto [p, x]: queries) {
        if (p >= 0) {
            add(sum, inv[b[p]], -b[p]);
            add(cnt, inv[b[p]], -1);
            h.erase(h.lower_bound(b[p]));
            h.insert(b[p] = x);
            add(cnt, inv[x], 1);
            add(sum, inv[x], x);
        } else {
            int l = *h.begin(), r = *h.rbegin() + 1;
            long double ans = 0;
            while (l < r) {
                int mid = l + (r - l) / 2;
                mid = *prev(h.upper_bound(mid));
                ll area = query(cnt, inv[mid]) * mid - query(sum, inv[mid]);
                if (area < x) {
                    auto it = h.upper_bound(mid);
                    if (it == h.end()) l = r;
                    else l = *it;
                } else r = mid;
            }
            if (l > *h.rbegin()) {
                ll area = 1LL * *h.rbegin() * n - query(sum, m - 1);
                ans = 1.L * (x - area) / n + *h.rbegin();
            } else {
                ll c = query(cnt, inv[l]);
                ll area = c * l - query(sum, inv[l]);
                ans = l - 1.L * (area - x) / query(cnt, inv[l] - 1);
            }
            println("{:.6f}", ans);
        }
    }
}


int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
