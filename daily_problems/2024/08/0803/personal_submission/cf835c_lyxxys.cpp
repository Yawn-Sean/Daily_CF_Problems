#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 300, mod = 1e9 + 7, inf = 1e9;

int f[15][N][N], g[15][N][N];
void solve(){
    int n, q, up;
    cin >> n >> q >> up;
    for (int i = 1; i <= n; ++ i){
        int x, y, c;
        cin >> x >> y >> c;
        for (int j = 0; j <= up; ++ j) g[j][x][y] += (c+j)%(up+1);
    }
    for (int p = 0; p <= up; ++ p){
        for (int i = 1; i <= 100; ++ i){
            for (int j = 1; j <= 100; ++ j){
                f[p][i][j] = f[p][i - 1][j] + f[p][i][j - 1] - f[p][i - 1][j - 1];
                f[p][i][j] += g[p][i][j];
            }
        }
    }

    while (q--){
        int ts, x1, y1, x2, y2;
        cin >> ts >> x1 >> y1 >> x2 >> y2;
        ts %= up+1;
        int res = f[ts][x2][y2]-f[ts][x2][y1-1]-f[ts][x1-1][y2] + f[ts][x1-1][y1-1];
        cout << res << "\n";
    }
}
