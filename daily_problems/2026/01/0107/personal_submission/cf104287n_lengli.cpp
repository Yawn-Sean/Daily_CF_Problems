#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<long long> outs;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<long long>> path(n);

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            --u; --v;

            // encode (w, v) into one number: w*n + v
            path[u].push_back(w * n + v);
            path[v].push_back(w * n + u);
        }

        vector<int> parent(n, -1);
        vector<int> que;
        que.reserve(n);
        que.push_back(0);

        // BFS to get parent order
        for (int idx = 0; idx < (int)que.size(); ++idx) {
            int u = que[idx];
            for (auto msk : path[u]) {
                long long w = msk / n;
                int v = (int)(msk % n);
                if (parent[u] != v) {
                    parent[v] = u;
                    que.push_back(v);
                }
            }
        }

        vector<long long> dp0(n, 0), dp1(n, 0);

        // tree DP from leaves to root
        for (int idx = (int)que.size() - 1; idx >= 0; --idx) {
            int u = que[idx];
            long long v1 = 0, v2 = 0;

            for (auto msk : path[u]) {
                long long w = msk / n;
                int v = (int)(msk % n);

                if (parent[v] == u) {
                    long long nw = w + dp0[v];
                    if (nw > v1) { v2 = v1; v1 = nw; }
                    else if (nw > v2) { v2 = nw; }

                    dp1[u] = max(dp1[u], dp1[v]);
                }
            }

            dp0[u] = v1;
            dp1[u] = max(dp1[u], v1 + v2);
        }

        vector<long long> up_dp0(n, 0), up_dp1(n, 0);

        // reroot DP
        for (int u : que) {
            long long v1 = up_dp0[u], v2 = 0, v3 = 0;
            long long w1 = 0, w2 = 0;

            for (auto msk : path[u]) {
                long long w = msk / n;
                int v = (int)(msk % n);

                if (parent[v] == u) {
                    long long nw = w + dp0[v];

                    if (nw > v1) { v3 = v2; v2 = v1; v1 = nw; }
                    else if (nw > v2) { v3 = v2; v2 = nw; }
                    else if (nw > v3) { v3 = nw; }

                    if (dp1[v] > w1) { w2 = w1; w1 = dp1[v]; }
                    else if (dp1[v] > w2) { w2 = dp1[v]; }
                }
            }

            for (auto msk : path[u]) {
                long long w = msk / n;
                int v = (int)(msk % n);

                if (parent[v] == u) {
                    long long nw = w + dp0[v];

                    if (nw == v1) {
                        up_dp0[v] = v2 + w;
                        up_dp1[v] = v2 + v3;
                    } else if (nw == v2) {
                        up_dp0[v] = v1 + w;
                        up_dp1[v] = v1 + v3;
                    } else {
                        up_dp0[v] = v1 + w;
                        up_dp1[v] = v1 + v2;
                    }

                    if (dp1[v] == w1)
                        up_dp1[v] = max(up_dp1[v], w2);
                    else
                        up_dp1[v] = max(up_dp1[v], w1);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, min(dp1[i], up_dp1[i]));

        outs.push_back(ans);
    }

    for (auto x : outs) cout << x << '\n';

    return 0;
}
