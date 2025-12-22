#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

/*
本质上就是矩阵快速幂求斐波那契第 n 项 f(n)
但是有一个问题，我们要求的是 2^(f(n)) % mod
但我们只能求出 f(n) % mod
2^(f(n) % mod) % mod 和 2^(f(n)) % mod 似乎并不是一回事
我们考虑这样一个事情，把 f(n) 表示成 k * mod + r，k 可能是很大的数
2^(k * mod + r) % mod 如何求？
我们拆一下，最后就是算 2^mod * 2^mod ... * 2^mod * 2^r % mod
2^mod % mod 有什么说法吗？不太清楚，但是能先算出来，假设是 res
那么就是 res^k * 2^r % mod，但是 k 大概是算不出来的
哦，可以考虑费马小定理
a^(p - 1) % p = 1
所以 2^(mod - 1) % mod = 1
我们可以矩阵快速幂求 f(n) 时对 mod - 1 取模
然后拆成 2^(k * (mod - 1) + r) % mod 即可
去掉那些 1，求的就是 2^r % mod
f(i)      0 1 f(i - 1) 
f(i + 1)  1 1 f(i)
*/

void solve() {
    LL n;
    cin >> n;
    
    LL t[2][2] = {
        {0, 1},
        {1, 1}    
    };
    
    const int mod = 998244353;
    
    auto mat_mul = [&] (LL a[][2], LL b[][2], int mod) -> void {
        LL res[2][2] = {{0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res[i][j] += a[i][k] * b[k][j];
                    res[i][j] %= mod;
                }
            }
        }    
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                a[i][j] = res[i][j];
            }
        }
    };
    
    auto mat_qpow = [&] (LL a[][2], LL b, int mod) -> void {
        LL res[2][2] = {
            {1, 0},
            {0, 1}    
        };
        LL base[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                base[i][j] = a[i][j];
            }
        }
        
        while (b) {
            if (b & 1) {
                mat_mul(res, base, mod);
            }
            mat_mul(base, base, mod);
            b >>= 1;
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                a[i][j] = res[i][j];
            }
        }
    };
    
    auto qpow = [&] (LL a, LL b, int mod) -> LL {
        LL res = 1, base = a;
        while (b) {
            if (b & 1) {
                res = res * base % mod;
            }
            base = base * base % mod;
            b >>= 1;
        }
        return res % mod;
    };
    
    mat_qpow(t, n, mod - 1);
    
    LL power = t[0][1];
    cout << qpow(2, power, mod) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
