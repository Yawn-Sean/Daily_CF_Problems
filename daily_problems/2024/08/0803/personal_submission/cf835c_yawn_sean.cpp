#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, c;
    cin >> n >> q >> c;

    vector<vector<int>> grid(c + 1, vector<int>(101 * 101));

    function<int(int, int)> f = [] (int x, int y) {return x * 101 + y;};

    while (n --) {
        int x, y, s;
        cin >> x >> y >> s;
        for (int i = 0; i <= c; i ++) {
            grid[i][f(x, y)] += (s + i) % (c + 1);
        }
    }

    for (int i = 0; i <= c; i ++) {
        for (int x = 0; x <= 100; x ++) {
            for (int y = 0; y < 100; y ++) {
                grid[i][f(x, y + 1)] += grid[i][f(x, y)];
            }
        }
        for (int y = 0; y <= 100; y ++) {
            for (int x = 0; x < 100; x ++) {
                grid[i][f(x + 1, y)] += grid[i][f(x, y)];
            }
        }
    }

    while (q --) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= c + 1;
        cout << grid[t][f(x2, y2)] - grid[t][f(x1 - 1, y2)] - grid[t][f(x2, y1 - 1)] + grid[t][f(x1 - 1, y1 - 1)] << '\n';
    }

    return 0;
}