#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

struct Factorial {
    int n;
    vector<long long> fac, fac_inv;

    static long long mod_pow(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }

    Factorial(int n) : n(n), fac(n + 1), fac_inv(n + 1) {
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % MOD;

        fac_inv[n] = mod_pow(fac[n], MOD - 2);
        for (int i = n; i > 0; i--)
            fac_inv[i - 1] = fac_inv[i] * i % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int M = 200000;
    Factorial f(M);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        unordered_set<int> s;
        s.reserve(k + 1);

        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        s.insert(n);  

        long long ans = f.fac[n];
        long long t = 1;

        for (int x = 1; x <= n; x++) {
            if (s.count(x)) {
                ans = ans * f.fac_inv[t] % MOD;
                t = 1;
            } else {
                t += 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
