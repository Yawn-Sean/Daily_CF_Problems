#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<string> outs;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> path(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            u--,v--;
            path[u].push_back(v);
            path[v].push_back(u);
        }

        bool flg = true;
        int rt = -1;
        for (int i = 0; i < n; ++i) {
            if ((int)path[i].size() > 3) {
                flg = false;
            } else if ((int)path[i].size() == 3) {
                rt = i;
            }
        }

        if (!flg) {
            outs.push_back("NO");
        } else if (rt != -1) {
            vector<int> parent(n, -1);
            queue<int> que;
            que.push(rt);

            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (int v : path[u]) {
                    if (parent[u] != v) {
                        parent[v] = u;
                        que.push(v);
                    }
                }
            }

            vector<int> vis(n, 0);

            for (int i = 0; i < n; ++i) {
                if ((int)path[i].size() == 3) {
                    int cur = i;
                    while (cur >= 0 && !vis[cur]) {
                        vis[cur] = 1;
                        cur = parent[cur];
                    }
                }
            }

            for (int i = 0; i < n; ++i) {
                int cnt = 0;
                for (int j : path[i]) {
                    cnt += vis[j];
                }
                if (cnt >= 3) flg = false;
            }

            outs.push_back(flg ? "YES" : "NO");
        } else {
            outs.push_back("YES");
        }
    }

    for (auto &s : outs) {
        cout << s << '\n';
    }

    return 0;
}
