#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1050, mod = 1e9+7, inf = 1e9;
int f[N][N][2], Pre[N], Suf[N];  //Pre：前缀右方向，Suf：后缀左方向
int n, k;

void solve(){
    cin >> n >> k;
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n+1; ++ i) Pre[i] = Suf[i] = 0;
    // 初始化
    if (k > 1)
        for (int i = n; i >= 1; -- i) f[i][k-1][0] = 1, Suf[i] = Suf[i+1] + 1;

    // 转移，衰变年龄为j的粒子只可能从衰变年龄从j+1的粒子转移过来，左0右1，O(nk)
    for (int j = k-2; j > 0; -- j){
        for (int i = n, sum = 0; i >= 1; -- i){
            f[i][j][0] = (f[i][j][0] + Pre[i-1]) % mod;
            f[i][j][1] = (f[i][j][1] + Suf[i+1]) % mod;
            Suf[i+1] = sum, sum = (sum + f[i][j][0]) % mod;
        }
        for (int i = 1; i <= n; ++ i){
            Pre[i] = (Pre[i-1] + f[i][j][1]) % mod;
        }
    }
    // 计数
    int res = 1;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j < k; ++ j){
            for (int t = 0; t < 2; ++ t){
                res = (res + f[i][j][t]) % mod;
            }
        }
    }
    
    cout << res << "\n";
}

int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
