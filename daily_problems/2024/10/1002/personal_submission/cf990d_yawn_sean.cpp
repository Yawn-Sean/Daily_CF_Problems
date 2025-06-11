#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<int>> grid(n, vector<int>(n, 0));

    if (a > 1) {
        if (b > 1) return cout << "NO", 0;
        
        for (int i = 0; i <= n - a; i ++) {
            for (int j = 0; j <= n - a; j ++) {
                if (i != j) grid[i][j] = 1;
            }
        }
    }
    else {
        if (b > 1) {
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++) {
                    if (i != j) grid[i][j] = 1;
                }
            }
            for (int i = 0; i <= n - b; i ++) {
                for (int j = 0; j <= n - b; j ++) {
                    if (i != j) grid[i][j] = 0;
                }
            }
        }
        else {
            if (n == 2 || n == 3) return cout << "NO", 0;
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++) {
                    if (abs(i - j) == 1) grid[i][j] = 1;
                }
            }
        }
    }

    cout << "YES\n";
    for (auto &x: grid) {
        for (auto &v: x) cout << v;
        cout << '\n';
    }

    return 0;
}