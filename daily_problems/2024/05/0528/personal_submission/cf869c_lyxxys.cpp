#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5050, mod = 998244353;
int fact[N], comb[N][N];

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i <= 5000; ++ i)
        for (int j = 0; j <= i; ++ j)
            if (!j) comb[i][j] = 1;
            else comb[i][j] += comb[i-1][j-1]+comb[i-1][j], comb[i][j] %= mod;
    fact[0] = 1;
    for (int i = 1; i <= 5000; ++ i) fact[i] = 1ll*i*fact[i-1]%mod;

    auto func = [&](int x, int y)->int{
        int res = 0;
        for (int i = 0; i <= min(x, y); ++ i)
            res += 1ll*comb[x][i]*comb[y][i]%mod * fact[i]%mod, res %= mod;
        return res;
    };

    cout << (1ll*func(a, b)*func(b, c)%mod * func(a, c)%mod) << "\n";
}  
