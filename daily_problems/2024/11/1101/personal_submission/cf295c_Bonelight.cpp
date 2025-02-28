/*
    Bonelight * v *
    20241031：重 走 西 游 路
    登 神 长 阶， 灯 升 长 阶
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    const int MOD = 1e9 + 7;
    auto M = [&](int x){return (x % MOD + MOD) % MOD;};
    int n,k; cin >> n >> k;
    k /= 50;
    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i ++){
        int x; cin >> x;
        if(x == 50) c1 ++;
        else c2 ++;
    }
    vector<vector<int>> C(51, vector<int>(51));
    for(int i = 0; i <= 50; i ++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j ++){
            C[i][j] = M(C[i - 1][j] + C[i - 1][j - 1]);
        }
    }
    vector<vector<int>> dp(c1 + 1, vector<int>(c2 + 1));
    vector<vector<int>> vis(c1 + 1, vector<int>(c2 + 1));
    vector<vector<int>> ndp(c1 + 1, vector<int>(c2 + 1));
    vector<vector<int>> nvis(c1 + 1, vector<int>(c2 + 1));

    dp[0][0] = 1;
    vis[0][0] = 1;

    for(int i = 0; i <= 2 * n; i ++){

        for(int x = 0; x <= c1; x ++){ // A -> B
            for(int y = 0; y <= c2; y ++){
                if(!vis[x][y]) continue;

                for(int dx = 0; x + dx <= c1; dx ++){
                    for(int dy = 0; y + dy <= c2; dy ++){
                        if((dx || dy) && dx + dy * 2 <= k){
                            int &v = ndp[x + dx][y + dy];
                            int Co = M(C[c1 - x][dx]*C[c2 - y][dy]);
                            v = M(v + M(dp[x][y] * Co));
                            nvis[x + dx][y + dy] = 1;
                        }
                    }
                }
            }
        }

        dp = ndp; vis = nvis;
        fill(begin(ndp), end(ndp), vector<int>(c2 + 1));
        fill(begin(nvis), end(nvis), vector<int>(c2 + 1));

        if(vis[c1][c2]){
            cout << 2 * i + 1 << endl;
            cout << dp[c1][c2] << endl;
            return;
        }

        for(int x = 0; x <= c1; x ++){  // A <- B
            for(int y = 0; y <= c2; y ++){
                if(!vis[x][y]) continue;

                for(int dx = 0; dx <= x; dx ++){
                    for(int dy = 0; dy <= y; dy ++){
                        if((dx || dy) && dx + dy * 2 <= k){
                            nvis[x - dx][y - dy] = 1;
                            int &v = ndp[x - dx][y - dy] ;
                            int Co = M(C[x][dx]*C[y][dy]);
                            v = M(v + M(dp[x][y] * Co));
                        }
                    }
                }
            }
        }
        dp = ndp; vis = nvis;
        fill(begin(ndp), end(ndp), vector<int>(c2 + 1));
        fill(begin(nvis), end(nvis), vector<int>(c2 + 1));
    }
    cout << -1 << endl << 0 << endl;
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
