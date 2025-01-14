#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divide, I conquer!

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

        int k1;
        cin >> k1;

        vector<int> nodes1(k1);
        for (auto &v: nodes1)
            cin >> v, v --;

        int k2;
        cin >> k2;

        vector<int> nodes2(k2);
        for (auto &v: nodes2)
            cin >> v, v --;
        
        vector<int> vis1(n, 0), vis2(n, 0);
        for (auto &v: nodes1) vis1[v] = 1;
        for (auto &v: nodes2) vis2[v] = 1;

        int node;

        cout << "B " << nodes2[0] + 1 << endl;
        cin >> node, node --;

        if (vis1[node]) cout << "C " << node + 1 << endl;
        else {
            vector<int> vis(n, 0);
            vis[node] = 1;

            queue<int> que;
            que.emplace(node);

            while (!que.empty()) {
                int u = que.front();
                que.pop();

                if (vis1[u]) {
                    cout << "A " << u + 1 << endl;
                    cin >> node, node --;
                    cout << "C " << (vis2[node] ? u + 1 : -1) << endl;
                    break;
                }

                for (auto &v: path[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        que.push(v);
                    }
                }
            }
        }
    }

    return 0;
}