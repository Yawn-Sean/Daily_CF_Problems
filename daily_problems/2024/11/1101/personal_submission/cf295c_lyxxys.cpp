#include <bits/stdc++.h>
using namespace std;

void solve(){
    const int mod = 1e9+7;
    int n, k, c1 = 0, c2 = 0;
    cin >> n >> k;
    k /= 50;
    for (int i = 0, x; i < n; ++ i){
        cin >> x;
        if (x == 50) c1 += 1;
        else c2 += 1;
    }

    vector <vector<int>> comb(51, vector<int>(51));
    vector<vector<vector<int>>> f(4*n+1, vector<vector<int>>(n+1, vector<int>(n+1)));
    vector<vector<vector<int>>> vis(4*n+1, vector<vector<int>>(n+1, vector<int>(n+1)));

    for (int i = 0; i <= 50; ++ i){
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; ++ j){
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
            if (comb[i][j] >= mod) comb[i][j] -= mod;
        }
    }

    auto combs = [&](int a, int b, int u, int v)->int{
        return 1ll * comb[a][b] * comb[u][v] % mod;
    };

    f[0][0][0] = 1;
    vis[0][0][0] = 1;
    
    for (int r = 0; r <= 2*n; ++ r){
        for (int i = 0; i <= c1; ++ i){
            for (int j = 0; j <= c2; ++ j){
                if (!vis[r][i][j]) continue;
                for (int x = 0; x <= c1-i; ++ x){
                    for (int y = 0; y <= c2-j; ++ y){
                        if (x+2*y <= k){
                            vis[r+1][i+x][j+y] = 1;
                            f[r+1][i+x][j+y] += 1ll*f[r][i][j] * combs(c1-i,x,c2-j,y) % mod;
                            if (f[r+1][i+x][j+y] >= mod) f[r+1][i+x][j+y] -= mod;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i <= c1; ++ i){
            for (int j = 0; j <= c2; ++ j){
                f[r][i][j] = f[r+1][i][j];
                vis[r][i][j] = vis[r+1][i][j];
                f[r+1][i][j] = 0;
                vis[r+1][i][j] = 0;
            }
        }
        if (vis[r][c1][c2]){
            cout << r*2+1 << "\n" << f[r][c1][c2] << "\n";
            return;
        }
 
        for (int i = 0; i <= c1; ++ i){
            for (int j = 0; j <= c2; ++ j){
                if (!vis[r][i][j]) continue;
                for (int x = 0; x <= i; ++ x){
                    for (int y = 0; y <= j; ++ y){
                        if (x+2*y <= k && (x > 0 || y > 0)){
                            vis[r+1][i-x][j-y] = 1;
                            f[r+1][i-x][j-y] += 1ll*f[r][i][j] * combs(i,x,j,y) % mod;
                            if (f[r+1][i-x][j-y] >= mod) f[r+1][i-x][j-y] -= mod;
                        }
                    }
                }
            }
        }
    }

    cout << -1 << "\n" << 0 << "\n";
}
