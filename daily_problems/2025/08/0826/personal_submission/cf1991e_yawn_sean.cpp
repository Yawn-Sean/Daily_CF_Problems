#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> path(n);

        for (int i = 0; i < m; i ++) {
            int u, v;
            cin >> u >> v;
            u --, v --;
            path[u].emplace_back(v);
            path[v].emplace_back(u);
        }

        vector<int> col(n, -1), v0, v1;
        bool flg = true;

        auto dfs = [&] (auto &self, int u) -> void {
            if (col[u] == 0) v0.emplace_back(u);
            else v1.emplace_back(u);

            for (auto &v: path[u]) {
                if (col[v] == -1) {
                    col[v] = col[u] ^ 1;
                    self(self, v);
                }
                else if (col[u] == col[v])
                    flg = false;
            }
        };

        col[0] = 0;
        dfs(dfs, 0);

        if (flg) {
            cout << "Bob" << endl;
            for (int i = 0; i < n; i ++) {
                int c1, c2;
                cin >> c1 >> c2;

                if ((c1 == 1 || c2 == 1) && !v0.empty()) {
                    int x = v0.back() + 1;
                    v0.pop_back();
                    cout << x << ' ' << 1 << endl;
                }
                else if ((c1 == 2 || c2 == 2) && !v1.empty()) {
                    int x = v1.back() + 1;
                    v1.pop_back();
                    cout << x << ' ' << 2 << endl;
                }
                else if (!v0.empty()) {
                    int x = v0.back() + 1;
                    v0.pop_back();
                    cout << x << ' ' << 3 << endl;
                }
                else {
                    int x = v1.back() + 1;
                    v1.pop_back();
                    cout << x << ' ' << 3 << endl;
                }
            }
        }
        else {
            cout << "Alice" << endl;
            for (int i = 0; i < n; i ++) {
                cout << "1 2" << endl;
                int idx, val;
                cin >> idx >> val;
            }
        }
    }

    return 0;
}