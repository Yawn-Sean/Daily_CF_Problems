#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> g(n, vector<int>(m));
    vector<int> r_min(n, inf);
    vector<int> c_min(m, inf);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &g[i][j]);
            r_min[i] = min(r_min[i], g[i][j]);
            c_min[j] = min(c_min[j], g[i][j]);
        }
    }
    map<int, int> r_moves, c_moves;
    auto check = [&] () -> bool {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] != r_moves[i] + c_moves[j]) return false;
            }
        }
        return true;
    };
    tuple<int, map<int, int>, map<int, int>> ans = make_tuple(inf, r_moves, c_moves);
    for (int k1 = 0; k1 <= g[0][0]; k1++) if (k1 <= r_min[0] && g[0][0] - k1 <= c_min[0]) {
        r_moves.clear(), c_moves.clear();
        int tot = g[0][0];
        int k2 = g[0][0] - k1;
        r_moves[0] = k1;
        c_moves[0] = k2;
        for (int i = 1; i < n; i++) {
            r_moves[i] = g[i][0] - k2;
            tot += g[i][0] - k2;
        }
        for (int i = 1; i < m; i++) {
            c_moves[i] = g[0][i] - k1;
            tot += g[0][i] - k1;
        }
        if (check()) {
            ans = min(ans, make_tuple(tot, r_moves, c_moves));
        }
    }
    auto& [tot, rs, cs] = ans;
    if (tot == inf) {
        printf("-1\n");
    } else {
        printf("%d\n", tot);
        for (auto& [idx, cnt] : rs) if (cnt) {
            for (int k = 0; k < cnt; k++) {
                printf("row %d\n", idx + 1);
            }
        }
        for (auto& [idx, cnt] : cs) if (cnt) {
            for (int k = 0; k < cnt; k++) {
                printf("col %d\n", idx + 1);
            }
        }
    }
    return 0;
}

