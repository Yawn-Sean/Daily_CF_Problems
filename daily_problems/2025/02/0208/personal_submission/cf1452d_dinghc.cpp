#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int mod = 998'244'353;

int fast_pow(int64 a, int64 b) {
    int64 ans = 1LL;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}
int64 inv(int a) {
    return a <= 1 ? a : mod - static_cast<int64>(mod / a) * inv(mod % a) % mod;
}

int main() {
    int n;
    scanf("%d", &n);
    int f0 = 0, f1 = 1;
    for (int i = 2; i <= n; i++) {
        int nf = (f0 + f1) % mod;
        f0 = f1, f1 = nf;
    }
    int ans = 1LL * f1 * inv(fast_pow(2, n)) % mod;
    printf("%d\n", ans);
    return 0;
}

