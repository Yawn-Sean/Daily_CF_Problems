#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<vector<int>> path(n);
        for (int i = 0; i < n - 1; i ++) {
            int u, v;
            cin >> u >> v;
            u --, v --;
            path[u].emplace_back(v);
            path[v].emplace_back(u);
        }

        bool flg = true;
        int rt = -1;

        for (int i = 0; i < n; i ++) {
            if (path[i].size() > 3) flg = false;
            else if (path[i].size() == 3) rt = i;
        }

        if (!flg) cout << "NO\n";
        else if (rt != -1) {
            vector<int> parent(n, -1);
            auto dfs = [&] (auto &self, int u, int p) -> void {
                parent[u] = p;
                for (auto &v: path[u]) {
                    if (v != p) {
                        self(self, v, u);
                    }
                }
            };
            dfs(dfs, rt, -1);

            vector<int> vis(n, 0);
            for (int i = 0; i < n; i ++) {
                if (path[i].size() == 3) {
                    int cur = i;
                    while (cur >= 0 && !vis[cur]) {
                        vis[cur] = 1;
                        cur = parent[cur];
                    }
                }
            }

            for (int i = 0; i < n; i ++) {
                int v = 0;
                for (auto &j: path[i]) v += vis[j];
                if (v >= 3) flg = false;
            }

            cout << (flg ? "YES\n" : "NO\n");
        }
        else cout << "YES\n";
    }

	return 0;
}