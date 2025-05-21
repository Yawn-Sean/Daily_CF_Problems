#include <bits/stdc++.h>

using namespace std;
constexpr int S = 50;
char grid[S + 1][S + 1];
int n, m;

bool solve() {
    vector<pair<int, int>> rows(n, make_pair(-1, -1));
    vector<pair<int, int>> cols(m, make_pair(-1, -1));
    for (int i = 0; i < n; i++) {
        auto& [l, r] = rows[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                if (r >= 0 && j - r > 1) return false;
                if (l == -1) l = j;
                r = j;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        auto& [u, d] = cols[i];
        for (int j = 0; j < n; j++) {
            if (grid[j][i] == 'B') {
                if (d >= 0 && j - d > 1) return false;
                if (u == -1) u = j;
                d = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (grid[i][j] == 'B') {
            for (int p = i + 1; p < n; p++) {
                for (int q = 0; q < m; q++) if (q != j && grid[p][q] == 'B') {
                    auto& [u, d] = cols[j];
                    auto& [l, r] = rows[i];
                    if (!(p >= u && p <= d || q >= l && q <= r)) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    if (solve()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

