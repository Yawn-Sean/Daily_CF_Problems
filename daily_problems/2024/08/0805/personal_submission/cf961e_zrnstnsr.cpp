#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n;
    // from tsreaper
    auto lb = [&](int x) { return x & -x; };
    auto add = [&](vector<int> &tree, int pos, int val) {
        for (; pos <= n; pos += lb(pos)) tree[pos] += val;
    };
    auto query = [&](vector<int> &tree, int pos) {
        int res = 0;
        for (; pos; pos -= lb(pos)) res += tree[pos];
        return res;
    };

    cin >> n;
    vector<int> a(n+1), tree(n+1);
    vector<pair<int, int>> b(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i-1] = {a[i], i};
    }
    sort(b.rbegin(), b.rend());
    long long ans = 0;
    auto it = b.begin();
    for (int i = n - 1; i >= 1; --i) {
        while (it != b.end() && it->first >= i) add(tree, it++->second, 1);
        int l = i, r = min(n, i + max(a[i] - i, 0));
        if (l >= r) continue;
        ans += query(tree, r) - query(tree, l);
    }
    cout << ans << endl;
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
