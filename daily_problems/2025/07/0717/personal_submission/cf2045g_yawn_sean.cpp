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

    int n, m, x;
    cin >> n >> m >> x;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    vector<int> pws(19);
    for (int i = -9; i <= 9; i ++) {
        int val = 1;
        for (int j = 0; j < x; j ++)
            val *= i;
        pws[9 + i] = val;
    }

    vector<vector<long long>> dist(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (i) dist[i][j] = dist[i - 1][j] + pws[9 + grid[i - 1][j] - grid[i][j]];
            if (j) dist[i][j] = dist[i][j - 1] + pws[9 + grid[i][j - 1] - grid[i][j]];
        }
    }

    bool flg = true;
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (i && dist[i][j] != dist[i - 1][j] + pws[9 + grid[i - 1][j] - grid[i][j]]) flg = false;
            if (j && dist[i][j] != dist[i][j - 1] + pws[9 + grid[i][j - 1] - grid[i][j]]) flg = false;
        }
    }

    int q;
    cin >> q;

    while (q --) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 --, y1 --, x2 --, y2 --;
        if (flg) cout << dist[x2][y2] - dist[x1][y1] << '\n';
        else cout << "INVALID\n";
    }

    return 0;
}