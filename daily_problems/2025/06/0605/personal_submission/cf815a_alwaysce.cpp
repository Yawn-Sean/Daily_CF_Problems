#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    vector<pair<string,int>> ops;
    auto op = [&](int dim) {
        if (dim == 0) {
            // row first
            for (int i = 0; i < n; i++) {
                int rmn = 501;
                for (int j = 0; j < m; j++) {
                    rmn = min(rmn, g[i][j]);
                }
                if (rmn > 0) {
                    for (int num_op = 0; num_op < rmn; num_op++) {
                        ops.emplace_back("row", i + 1);
                    }
                    for (int j = 0; j < m; j++) {
                        g[i][j] -= rmn;
                    }
                }
            }
        } else {
            // col first
            for (int j = 0; j < m; j++) {
                int cmn = 501;
                for (int i = 0; i < n; i++) {
                    cmn = min(cmn, g[i][j]);
                }
                if (cmn > 0) {
                    for (int num_op = 0; num_op < cmn; num_op++) {
                        ops.emplace_back("col", j + 1);
                    }
                    for (int i = 0; i < n; i++) {
                        g[i][j] -= cmn;
                    }
                }
            }
        }
    };

    if (n < m) {
        op(0);
        op(1);
    } else {
        op(1);
        op(0);
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != 0) {
                ok = false;
                break;
            }
        }
    }

    if (!ok) {
        cout << -1 << endl;
    } else {
        cout << ops.size() << endl;
        for (auto& [k, v]: ops) {
            cout << k << ' ' << v << endl;
        }
    }
    return 0;
}
