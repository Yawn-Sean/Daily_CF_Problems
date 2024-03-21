/**
 * Created by 5cm/s on 2024/03/16 09:36:21.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

void elysia() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    while (m--) {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> vis(n), dis(n), fa(n);
    queue<int> Q({0});
    vis[0] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        int cnt = 0;
        for (int v: g[u]) {
            if (vis[v]) {
                if (dis[u] - dis[v] >= k) {
                    int ans = dis[u] - dis[v] + 1;
                    cout << ans << endl;
                    while (ans--) {
                        cout << u + 1 << " \n"[ans == 0];
                        u = fa[u];
                    }
                    return;
                }
            } else if (cnt < 1) {
                cnt++, vis[v] = 1, dis[v] = dis[u] + 1, fa[v] = u;
                Q.emplace(v);
                break;
            }
        }
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
