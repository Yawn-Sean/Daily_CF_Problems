#include <bits/stdc++.h>

using namespace std;
constexpr int N = 26;
constexpr int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    vector<map<int, int>> g(N);
    for (int i = 0; i < n; i++) {
        char a, b;
        int u, v, w;
        cin >> a >> b >> w;
        u = a - 'a', v = b - 'a';
        if (g[u].find(v) != g[u].end()) {
            w = min(w, g[u][v]);
        }
        g[u][v] = w;
    }
    if (s.length() != t.length()) {
        cout << "-1\n";
    } else {
        vector<vector<int>> costs(N, vector<int>(N, INF));
        for (int i = 0; i < N; i++) {
            costs[i][i] = 0;
            set<pair<int, int>> q;
            q.emplace(0, i);
            while (!q.empty()) {
                auto [w_u, u] = *q.begin(); q.erase(q.begin());
                for (auto& [v, w_v] : g[u]) {
                    if (costs[i][v] > w_u + w_v) {
                        auto it = q.lower_bound(make_pair(costs[i][v], v));
                        if (it != q.end()) q.erase(it);
                        costs[i][v] = w_u + w_v;
                        q.emplace(costs[i][v], v);
                    }
                }
            }
        }
        int n = s.length();
        string ans(n, ' ');
        bool ok = true;
        int total = 0;
        for (int i = 0; i < n; i++) {
            int u = s[i] - 'a';
            int v = t[i] - 'a';
            pair<int, int> res {INF, -1};
            for (int t = 0; t < N; t++) {
                res = min(res, pair<int, int>{ costs[u][t] + costs[v][t], t });
            }
            if (res.first >= INF) {
                ok = false;
                break;
            } else {
                ans[i] = res.second + 'a';
                total += res.first;
            }
        }
        if (ok) {
            cout << total << "\n";
            cout << ans << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}

