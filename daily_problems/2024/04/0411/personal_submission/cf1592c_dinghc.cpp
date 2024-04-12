#include <bits/stdc++.h>

using namespace std;
constexpr int MXN = 100001;
int a[MXN];
vector<int> g[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int xor_ = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            g[i] = vector<int>();
            xor_ ^= a[i];
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }

        if (xor_ == 0) {
            cout << "YES\n";
        } else if (k == 2) {
            cout << "NO\n";
        } else {
            int cnt = 0;
            function<int(int, int)> dfs = [&] (int u, int pa) {
                int curr = a[u];
                for (auto& v : g[u]) {
                    if (v != pa) {
                        int nx = dfs(v, u);
                        if (cnt > 1) break;
                        if (nx == xor_) {
                            cnt++;
                        } else {
                            curr ^= nx;
                        }
                    }
                }
                return curr;
            };
            dfs(0, -1);
            if (cnt > 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}

