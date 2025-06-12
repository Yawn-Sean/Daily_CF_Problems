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

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> path(m + n * m);
    vector<int> indeg(m + n * m, 0);

    int pt = m;

    for (int i = 0; i < n; i ++) {
        vector<int> idxs;
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] != -1) {
                idxs.push_back(j);
            }
        }
        sort(idxs.begin(), idxs.end(), [&](int x, int y) {return grid[i][x] < grid[i][y];});

        int l = 0, r = 0, last_node = -1;
        for (int j = 1; j < idxs.size(); j ++) {
            if (grid[i][idxs[j]] == grid[i][idxs[j - 1]])
                r = j;
            else {
                if (last_node != -1) {
                    for (int k = l; k <= r; k ++) {
                        path[last_node].push_back(idxs[k]);
                        indeg[idxs[k]] ++;
                    }
                }

                for (int k = l; k <= r; k ++) {
                    path[idxs[k]].emplace_back(pt);
                    indeg[pt] ++;
                }

                last_node = pt;
                pt ++;
                l = j, r = j;
            }
        }

        if (last_node != -1) {
            for (int k = l; k <= r; k ++) {
                path[last_node].push_back(idxs[k]);
                indeg[idxs[k]] ++;
            }
        }
    }

    vector<int> ans;
    vector<int> stk;

    for (int i = 0; i < m + n; i ++) {
        if (indeg[i] == 0) {
            stk.emplace_back(i);
        }
    }

    while (!stk.empty()) {
        int u = stk.back();
        stk.pop_back();

        if (u < m) ans.emplace_back(u);
        for (auto &v: path[u]) {
            indeg[v] --;
            if (indeg[v] == 0) {
                stk.emplace_back(v);
            }
        }
    }

    if (ans.size() == m)
        for (auto &x: ans) cout << x + 1 << ' ';
    else cout << -1;

    return 0;
}