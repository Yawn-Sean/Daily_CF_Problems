#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1050, inf = 0x3f3f3f3f, mod = 998244353;
ll f[N][2*N][4];
const int dx[][4] = 
{{0, 0, 0, -1}, {-1, 0, -2, -1}, {-1, -2, 0, -1}, {-1, 0, 0, 0}};
void solve(){
    int n, k;
    cin >> n >> k;
    // 初始化
    // for (int i = 0; i < 4; ++ i)
    //     f[0][0][i] = 1;
    f[1][1][3] = f[1][1][0] = 1;
    f[1][2][1] = f[1][2][2] = 1;

    for (int i = 2; i <= n; ++ i){
        for (int j = 1; j <= k; ++ j){
            for (int t = 0; t < 4; ++ t){
                for (int to = 0; to < 4; ++ to){
                    int lst = j + dx[t][to];
                    if (lst >= 1)
                        f[i][j][t] += f[i-1][lst][to], f[i][j][t] %= mod;
                }
            }  
        }
    }

    int res = 0;

    for (int i = 0; i < 4; ++ i)
        res += f[n][k][i], res %= mod;
    
    cout << res << "\n";
}
