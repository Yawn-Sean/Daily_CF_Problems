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

    vector<vector<pair<int, int>>> path(n), rev_path(n);

    while (m --) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        path[u].emplace_back(v, w);
        rev_path[v].emplace_back(u, w);
    }

    int inf = 2e9;

    auto shortest_path = [&] (vector<vector<pair<int, int>>> paths) -> vector<int> {
        vector<int> ans(n, inf);
        ans[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (ans[u] == d) {
                for (auto &[v, nd]: paths[u]) {
                    if (max(d, nd) < ans[v]) {
                        ans[v] = max(d, nd);
                        pq.push({ans[v], v});
                    }
                }
            }
        }

        return ans;
    };

    auto d1 = shortest_path(path);
    auto d2 = shortest_path(rev_path);

    for (int i = 0; i < n; i ++) {
        if (d2[i] > d1[i]) {
            return cout << "NO", 0;
        }
    }

    cout << "YES";

	return 0;
}