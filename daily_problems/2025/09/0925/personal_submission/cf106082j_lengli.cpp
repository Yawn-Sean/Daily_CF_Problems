#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int O; 
    std::cin>>O;
    vector<long long> xs(O), ys(O);
    for (int i = 0; i < O; ++i) cin >> xs[i] >> ys[i];

    int Q; 
    cin >> Q;
    vector<pair<int,int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        int s, e; cin >> s >> e; --s; --e;
        queries[i] = {s, e};
    }

    auto dist2 = [&](int i, int j)->ull {
        long long dx = xs[i] - xs[j];
        long long dy = ys[i] - ys[j];
        return (ull)(dx*dx + dy*dy);
    };

    const ull INF = numeric_limits<ull>::max()/4;
    vector<ull> best(O, INF);
    vector<int> parent(O, -1);
    vector<char> used(O, 0);

    best[0] = 0;

    vector<vector<pair<int, ull>>> g(O); 

    for (int it = 0; it < O; ++it) {
        int u = -1;
        ull bv = INF;
        for (int i = 0; i < O; ++i)
            if (!used[i] && best[i] < bv) { bv = best[i]; u = i; }

        used[u] = 1;
        if (parent[u] != -1) {
            ull w = best[u];
            g[u].push_back({parent[u], w});
            g[parent[u]].push_back({u, w});
        }

        for (int v = 0; v < O; ++v) if (!used[v]) {
            ull w = dist2(u, v);
            if (w < best[v]) { best[v] = w; parent[v] = u; }
        }
    }

    int LOG = 1;
    while ((1<<LOG) <= O) ++LOG;

    vector<int> depth(O, 0);
    vector<vector<int>> up(LOG, vector<int>(O, -1));
    vector<vector<ull>> mx(LOG, vector<ull>(O, 0));

    // root the MST at 0
    vector<int> st = {0};
    up[0][0] = -1; depth[0] = 0;
    vector<int> order; order.reserve(O);
    while (!st.empty()) {
        int u = st.back(); st.pop_back();
        order.push_back(u);
        for (auto [v,w]: g[u]) if (v != up[0][u]) {
            up[0][v] = u;
            mx[0][v] = w;
            depth[v] = depth[u] + 1;
            st.push_back(v);
        }
    }

    for (int k = 1; k < LOG; ++k) {
        for (int v = 0; v < O; ++v) {
            int a = up[k-1][v];
            if (a == -1) { up[k][v] = -1; mx[k][v] = mx[k-1][v]; }
            else {
                up[k][v] = up[k-1][a];
                mx[k][v] = max(mx[k-1][v], mx[k-1][a]);
            }
        }
    }

    auto max_on_path2 = [&](int u, int v)->ull {
        ull ans = 0;
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int k = 0; k < LOG; ++k) if (diff & (1<<k)) {
            ans = max(ans, mx[k][u]);
            u = up[k][u];
        }
        if (u == v) return ans;
        for (int k = LOG-1; k >= 0; --k) {
            if (up[k][u] != up[k][v]) {
                ans = max(ans, mx[k][u]);
                ans = max(ans, mx[k][v]);
                u = up[k][u];
                v = up[k][v];
            }
        }
        ans = max(ans, mx[0][u]);
        ans = max(ans, mx[0][v]);
        return ans;
    };

    cout.setf(std::ios::fixed); cout << setprecision(10);
    for (auto [s,e] : queries) {
        ull w2 = max_on_path2(s, e);
        long double ans = sqrt((long double)w2);
        cout << (double)ans << "\n";
    }
    return 0;
}
