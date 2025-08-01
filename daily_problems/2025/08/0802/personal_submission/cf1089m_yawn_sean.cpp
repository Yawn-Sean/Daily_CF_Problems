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

    vector<vector<string>> ans(3, vector<string>(3 * n, string(3 * n, '#')));

    for (int i = 1; i <= n; i ++) {
        int idx = 3 * i - 2;

        for (int j = 0; j < 3 * n; j ++)
            ans[0][idx][j] = '.', ans[2][j][idx] = '.';
        ans[2][3 * n - 1][idx] = '0' + i;

        ans[1][idx - 1][idx] = '.';
        ans[1][idx - 1][idx - 1] = '.';
        ans[0][idx - 1][idx - 1] = '.';

        for (int j = 1; j <= n; j ++) {
            int x;
            cin >> x;

            if (x) {
                int jdx = 3 * j - 2;
                ans[0][idx - 1][jdx] = '.';
                ans[1][idx - 1][jdx] = '.';
                ans[2][idx - 1][jdx] = '.';
            }
        }
    }

    cout << 3 * n << ' ' << 3 * n << ' ' << 3 << '\n';

    for (int i = 0; i < 3; i ++) {
        if (i) cout << '\n';
        for (auto &x: ans[i]) cout << x << '\n';
    }

    return 0;
}