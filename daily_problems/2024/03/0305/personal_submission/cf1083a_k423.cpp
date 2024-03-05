/**
 * Created by 5cm/s on 2024/03/05 11:11:58.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using i64 = int64_t;
using pii = pair<int, int>;

void elysia() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<pii>> g(n);
    for (int &x: a) cin >> x;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    i64 ans = ranges::max(a);
    function<i64(int, int)> dfs = [&](int u, int p) -> i64 {
        i64 v1 = 0, v2 = 0;
        for (auto &[v, w]: g[u]) {
            if (v == p) continue;
            i64 v3 = dfs(v, u) - w;
            if (v3 > v1) v2 = v1, v1 = v3;
            else if (v3 > v2) v2 = v3;
        }
        ans = max(ans, v1 + v2 + a[u]);
        return v1 + a[u];
    };
    dfs(0, -1);
    cout << ans << endl;
}

int main() {
#ifdef MEGURINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    clock_t start = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) elysia();
#ifdef MEGURINE
    cout << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}
