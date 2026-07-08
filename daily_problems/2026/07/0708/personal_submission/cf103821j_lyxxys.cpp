#include <bits/stdc++.h>

using i64 = long long;
namespace math {
    const int mod = 1e9 + 7;
    i64 pow(i64 x, i64 n){
        i64 res = 1;
        while (n > 0){
            if (n&1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
    class Comb {
    private:
        std::vector<i64> f, invF;
        void grow(int mx){
            int old_sz = f.size();
            f.resize(mx+1);
            for (int i = old_sz; i <= mx; ++ i){
                f[i] = f[i-1] * i % mod;
            }
            invF.resize(mx+1);
            invF[mx] = pow(f[mx], mod-2);
            for (int i = mx; i > old_sz; -- i){
                invF[i-1] = invF[i] * i % mod;
            }
        }
    public:
        explicit Comb(int mx){
            f.resize(1, 1);
            invF.resize(1, 1);
            grow(mx);
        }
        i64 fac(int n){
            if (n >= f.size()) grow(2*n);
            return f[n];
        }
        i64 inv_fac(int n){
            if (n >= f.size()) grow(2 * n);
            return invF[n];
        }
        i64 c(int n, int k){
            if (k < 0 || k > n) return 0;
            return fac(n) * inv_fac(k) % mod * inv_fac(n-k) % mod;
        }
    };
}

void solve() {
    constexpr int  mod = 1e9 + 7;
    math::Comb combs(1);

    int T;
    std::cin >> T;
    while (T--){
        int n, k;
        std::cin >> n >> k;
        std::vector<int> freq(n), cnts;
        for (int i = 0, x; i < n; ++ i){
            std::cin >> x;
            freq[x-1] += 1;
        }
        for (int i = 0; i < n; ++ i){
            freq[i] ? cnts.emplace_back(freq[i]) : 0;
        }

        std::vector<i64> g(k+1, 1), f(k+1, 0);
        for (int i = 1; i <= k; ++ i){
            for (auto &cnt : cnts){
                g[i] = g[i] * combs.c(cnt+i-1, i-1) % mod;
            }
        }

        f[1] = 1;
        for (int i = 2; i <= k; ++ i){
            for (int j = 1; j <= i-1; ++ j){
                f[i] += combs.c(i, j) * f[j] % mod;
                f[i] %= mod;
            }
            f[i] = (g[i] - f[i]) % mod;
            if (f[i] < 0){
                f[i] += mod;
            }
        }

        std::cout << f[k] << "\n";
    }

}
