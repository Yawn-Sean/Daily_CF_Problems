#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 26+26*27+10, inf = 0x3f3f3f3f, mod = 1e9+7;

void solve(){
    ll a, b, n, x;
    cin >> a >> b >> n >> x;

    auto multi = [&](vector<array<ll,2>> a, vector<array<ll,2>> b)->vector<array<ll,2>>{
        vector<array<ll,2>> c(2);
        for (int i = 0; i < 2; ++ i)
            for (int j = 0; j < 2; ++ j)
                for (int k = 0; k < 2; ++ k)
                    c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % mod;
        return c;
    };

    vector <array<ll,2>> with(2), to(2);
    with[0][0] = a, with[1][0] = b, with[1][1] = 1;
    to[0][0] = x, to[0][1] = 1;
    //求 to 对于右乘矩阵 with的n次幂
    while (n){
        if (n&1) to = multi((vector<array<ll,2>>)to, (vector<array<ll,2>>)with);
        with = multi((vector<array<ll,2>>)with, (vector<array<ll,2>>)with);
        n >>= 1;
    }

    cout << to[0][0] << "\n";
}
