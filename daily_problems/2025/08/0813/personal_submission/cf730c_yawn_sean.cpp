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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> path(n);
    while (m --) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    int w;
    cin >> w;

    vector<int> cs(w), ks(w), ps(w);
    for (int i = 0; i < w; i ++)
        cin >> cs[i] >> ks[i] >> ps[i], cs[i] --;
    
    vector<int> order(w);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return ps[i] < ps[j];});

    int q;
    cin >> q;

    while (q --) {
        int g, r, a;
        cin >> g >> r >> a;
        g --;
        vector<int> dis(n, n);
        dis[g] = 0;

        queue<int> q; q.push(g);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &v: path[u]) {
                if (dis[v] == n) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }

        int left = 0, right = n;
        while (left <= right) {
            int mid = (left + right) / 2;

            long long cost = 0;
            int cur = r;
            for (auto &i: order) {
                if (dis[cs[i]] <= mid) {
                    int val = min(cur, ks[i]);
                    cur -= val;
                    cost += 1ll * val * ps[i];
                }
            }

            if (cost <= a && cur == 0) right = mid - 1;
            else left = mid + 1;
        }

        cout << (left < n ? left : -1) << '\n';
    }

    return 0;
}