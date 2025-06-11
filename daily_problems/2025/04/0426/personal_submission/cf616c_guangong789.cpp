#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int MOD = 10;
const int inf = 0x3f3f3f3f;
const long long INF = LLONG_MAX;

int n, m;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<int> bin, rankk, cpt_size;

int findd(int i) {
    if (bin[i] != i) {
        bin[i] = findd(bin[i]);
    }
    return bin[i];
}

void merge(int u, int v) {
    int ru = findd(u), rv = findd(v);
    if (ru != rv) {
        if (rankk[ru] > rankk[rv]) {
            bin[rv] = ru;
            cpt_size[ru] += cpt_size[rv];
        } else if (rankk[ru] < rankk[rv]) {
            bin[ru] = rv;
            cpt_size[rv] += cpt_size[ru];
        } else {
            bin[rv] = ru;
            rankk[ru]++;
            cpt_size[ru] += cpt_size[rv];
        }
    }
}

bool ill(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    bin.resize(n * m);
    rankk.resize(n * m, 0);
    cpt_size.resize(n * m, 1);
    iota(bin.begin(), bin.end(), 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.') {
                int idx = i * m + j;
                for (auto [dx, dy] : dir) {
                    int x = i + dx, y = j + dy;
                    if (ill(x, y) && g[x][y] == '.') {
                        merge(idx, x * m + y);
                    }
                }
            }
        }
    }
    vector<string> res(n, string(m, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '*') {
                set<int> cur;
                for (auto [dx, dy] : dir) {
                    int x = i + dx, y = j + dy;
                    if (ill(x, y) && g[x][y] == '.') {
                        int new_idx = x * m + y;
                        cur.insert(findd(new_idx));
                    }
                }

                int total= 1;
                for (int root : cur) {
                    total += cpt_size[root] % MOD;
                }
                res[i][j] = (total % MOD) + '0';
            }
        }
    }
    for (auto& row : res) {
        cout << row << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}