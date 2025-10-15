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

    if (n + m > 2 && n + m < 5) cout << -1;
    else {
        vector<vector<int>> grid(n, vector<int>(m));
        int pt = 0;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if ((i + j) % 2) {
                    grid[i][j] = ++pt;
                }
            }
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if ((i + j) % 2 == 0) {
                    grid[i][j] = ++pt;
                }
            }
        }

        for (auto &x: grid) {
            for (auto &y: x) {
                cout << y << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}