#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int64 mod = 1'000'000'007;

int fast_pow(int64 a, int64 b) {
    int64 ans = 1LL;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}

int main() {
    int64 x, k;
    scanf("%lld%lld", &x, &k);
    int ans = 0;
    if (x != 0) {
        int pw = fast_pow(2, k);
        ans = (pw * 2 * (x % mod) % mod + mod - pw + 1) % mod;
    }
    printf("%d\n", ans);
    return 0;
}

