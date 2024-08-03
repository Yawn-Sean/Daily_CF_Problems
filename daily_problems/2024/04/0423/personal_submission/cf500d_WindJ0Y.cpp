#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int sp, ep, w, eid;
};

void work() {
    int n; cin >> n;

    vector<Edge> ori_edge (n - 1);
    vector<vector<Edge>> mmp(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --; v --;
        ori_edge[i] = {u, v, w, i};
        mmp[u].emplace_back(u, v, w, i);
        mmp[v].emplace_back(v, u, w, i);
    }

    vector<int> fa(n, -1);
    vector<int> sz(n, 0);

    function<void(int, int)> df_size = [&](int u, int f) {
        fa[u] = f;
        sz[u] = 1;
        for (auto e : mmp[u]) {
            int v = e.ep;
            if (v == f) continue;
            df_size(v, u);
            sz[u] += sz[v];
        }
    };
    df_size(0, -1);

    vector<double> ecnt(n - 1);
    double cd = 1.0 * n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < ori_edge.size(); i++) {
        int u = ori_edge[i].sp;
        int v = ori_edge[i].ep;

        int size_a = min(sz[u], sz[v]);
        int size_b = n - size_a;

        ecnt[i] = 1.0 * size_a * size_b * (size_a + size_b - 2) / cd;
    }

    double fans{};
    for (int i = 0; i < ori_edge.size(); i++) {
        fans += ecnt[i] * ori_edge[i].w;
    }

    int q; cin >> q;
    while (q--) {
        int eid, w;
        cin >> eid >> w;
        eid --;

        int delta = ori_edge[eid].w - w;
        ori_edge[eid].w = w;

        fans -= ecnt[eid] * delta;
        cout << fans << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(10);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}