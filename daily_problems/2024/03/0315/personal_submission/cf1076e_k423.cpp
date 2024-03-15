/**
 * Created by 5cm/s on 2024/03/15 10:43:26.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using pii = pair<int, int>;
using i64 = int64_t;

void elysia() {
    int n, q;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    cin >> q;
    vector<vector<pii>> qs(n);
    while (q--) {
        int u, d, x;
        cin >> u >> d >> x;
        qs[u - 1].emplace_back(d + 1, x);
    }

    vector<i64> ans(n), val(n);
    i64 tot = 0;
    function<void(int, int, int)> dfs = [&](int u, int p, int dep) {
        for (auto [d, x]: qs[u]) {
            val[dep] += x;
            if (dep + d < n) val[dep + d] -= x;
        }
        ans[u] = tot += val[dep];
        for (int v: g[u]) {
            if (v != p) {
                dfs(v, u, dep + 1);
            }
        }
        tot -= val[dep];
        for (auto [d, x]: qs[u]) {
            val[dep] -= x;
            if (dep + d < n) val[dep + d] += x;
        }
    };
    dfs(0, -1, 0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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
