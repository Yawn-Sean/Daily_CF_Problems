#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;

int __FAST_IO__ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

const long long inf = 1e17;
void solveD() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    long long ans = -inf;
    function<pll(int, int)> dfs = [&](int u, int p) {
        ll sum = a[u];
        ll max1 = -inf, max2 = -inf;
        for (int v : g[u]) {
            if (v == p) continue;
            auto [s, m] = dfs(v, u);
            sum += s;
            if (m > max1) {
                max2 = max1;
                max1 = m;
            } else if (m > max2) {
                max2 = m;
            }
        }
        ans = max(ans, max1 + max2);
        return make_pair(sum, max(sum, max1));
    };
    dfs(0, -1);
    if (ans < -1e16) cout << "Impossible";
    else cout << ans;
}

int main() {
    solveD();
}
