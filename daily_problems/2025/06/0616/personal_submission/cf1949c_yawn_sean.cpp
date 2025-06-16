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

    int n;
    cin >> n;

    vector<vector<int>> path(n);
    vector<int> degs(n, 0);

    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
        degs[u] ++, degs[v] ++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> val(n, 1);

    for (int i = 0; i < n; i ++) {
        if (degs[i] == 1) {
            pq.push({1, i});
        }
    }

    for (int i = 0; i < n - 1; i ++) {
        auto [d, u] = pq.top(); pq.pop();

        for (auto &v: path[u]) {
            if (val[v]) {
                if (val[v] < val[u]) return cout << "NO", 0;
                val[v] += val[u];
                val[u] = 0;

                degs[v] --;
                if (degs[v] == 1) pq.push({val[v], v});
            }
        }
    }
    cout << "YES";

    return 0;
}