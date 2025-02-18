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

    int mod = 1e9 + 7;
    vector<vector<int>> combs(51, vector<int>(51, 0));
    for (int i = 0; i <= 50; i ++) {
        combs[i][0] = 1;
        for (int j = 1; j <= i; j ++) {
            combs[i][j] = combs[i - 1][j] + combs[i - 1][j - 1];
            if (combs[i][j] >= mod) combs[i][j] -= mod;
        }
    }

    int n, k;
    cin >> n >> k;
    k /= 50;

    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if (x == 50) c1 ++;
        else c2 ++;
    }

    vector<vector<int>> dp(c1 + 1, vector<int>(c2 + 1, 0));
    vector<vector<int>> ndp(c1 + 1, vector<int>(c2 + 1, 0));
    vector<vector<int>> vis(c1 + 1, vector<int>(c2 + 1, 0));
    vector<vector<int>> nvis(c1 + 1, vector<int>(c2 + 1, 0));

    dp[0][0] = 1;
    vis[0][0] = 1;

    for (int i = 0; i <= 2 * n; i ++) {

        for (int x = 0; x <= c1; x ++) {
            for (int y = 0; y <= c2; y ++) {
                if (!vis[x][y]) continue;

                for (int nx = 0; x + nx <= c1; nx ++) {
                    for (int ny = 0; y + ny <= c2; ny ++) {
                        if (nx + 2 * ny <= k) {
                            ndp[x + nx][y + ny] += 1ll * dp[x][y] * combs[c1 - x][nx] % mod * combs[c2 - y][ny] % mod;
                            nvis[x + nx][y + ny] = 1;
                            if (ndp[x + nx][y + ny] >= mod)
                                ndp[x + nx][y + ny] -= mod;
                        }
                    }
                }
            }
        }

        for (int x = 0; x <= c1; x ++) {
            for (int y = 0; y <= c2; y ++) {
                dp[x][y] = ndp[x][y];
                vis[x][y] = nvis[x][y];
                ndp[x][y] = 0;
                nvis[x][y] = 0;
            }
        }

        if (vis[c1][c2]) {
            cout << 2 * i + 1 << '\n';
            cout << dp[c1][c2];
            return 0;
        }

        for (int x = 0; x <= c1; x ++) {
            for (int y = 0; y <= c2; y ++) {
                if (!vis[x][y]) continue;
                
                for (int nx = 0; nx <= x; nx ++) {
                    for (int ny = 0; ny <= y; ny ++) {
                        if ((nx > 0 || ny > 0) && nx + 2 * ny <= k) {
                            ndp[x - nx][y - ny] += 1ll * dp[x][y] * combs[x][nx] % mod * combs[y][ny] % mod;
                            nvis[x - nx][y - ny] = 1;
                            if (ndp[x - nx][y - ny] >= mod)
                                ndp[x - nx][y - ny] -= mod;
                        }
                    }
                }
            }
        }

        for (int x = 0; x <= c1; x ++) {
            for (int y = 0; y <= c2; y ++) {
                dp[x][y] = ndp[x][y];
                vis[x][y] = nvis[x][y];
                ndp[x][y] = 0;
                nvis[x][y] = 0;
            }
        }
    }

    cout << "-1\n0";

    return 0;
}