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

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '.') {
                char c = '0' + (i % 3) + (j % 3) * 3;
                grid[i][j] = c;
                if (j + 1 < m && grid[i][j + 1] == '.') grid[i][j + 1] = c;
                else if (i + 1 < n && grid[i + 1][j] == '.') grid[i + 1][j] = c;
                else {
                    if (j && grid[i][j - 1] != '#') grid[i][j] = grid[i][j - 1];
                    else if (i && grid[i - 1][j] != '#') grid[i][j] = grid[i - 1][j];
                    else if (j + 1 < m && grid[i][j + 1] != '#') grid[i][j] = grid[i][j + 1];
                    else cout << -1, exit(0);
                }
            }
        }
    }

    for (auto &s: grid) cout << s << '\n';

    return 0;
}