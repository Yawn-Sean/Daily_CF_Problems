#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<string> outs;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<ll>> path(n);

        auto encode = [&](ll x, ll y) {
            return x * n + y;
        };

        for (int i = 0; i < m; i++) {
            int u, v;
            ll c;
            cin >> u >> v >> c;
            u--;  
            v--;
            path[u].push_back(encode(c, v));
        }

        vector<vector<ll>> vis(2, vector<ll>(n, -2));
        vis[0][0] = -1;
        vis[1][0] = -1;

        queue<ll> que;
        que.push(0);  // 2*0 + 0

        while (!que.empty()) {
            ll msk = que.front();
            que.pop();

            ll u = msk / 2;
            ll time = msk % 2;

            for (ll edge : path[u]) {
                ll c = edge / n;
                ll v = edge % n;

                if (vis[time][u] != c) {
                    if (vis[0][v] == -2) {
                        vis[0][v] = c;
                        que.push(2 * v);
                    }
                    else if (vis[0][v] == c) {
                        continue;
                    }
                    else if (vis[1][v] == -2) {
                        vis[1][v] = c;
                        que.push(2 * v + 1);
                    }
                }
            }
        }

        string result;
        for (int i = 0; i < n; i++) {
            if (vis[0][i] != -2) {
                if (!result.empty()) result += " ";
                result += to_string(i + 1);
            }
        }

        outs.push_back(result);
    }

    for (auto &s : outs) {
        cout << s << "\n";
    }

    return 0;
}
