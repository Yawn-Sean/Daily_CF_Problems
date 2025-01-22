#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int64 mod = 1'000'000'007;
constexpr int A = 31;

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
    int n;
    scanf("%d", &n);
    vector<int> cnt(A + 1, 0);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        cnt[31 - __builtin_clz(x & -x)] += 1;
    }
    int ans = 0;
    for (int i = A - 1; i > 0; i--) {
        if (cnt[i] > 1) ans = ((ans + fast_pow(2, cnt[i] - 1 + cnt[i + 1])) % mod + mod - fast_pow(2, cnt[i + 1])) % mod;
        cnt[i] += cnt[i + 1];
    }
    ans = ((ans + fast_pow(2, cnt[0] + cnt[1])) % mod + mod - fast_pow(2, cnt[1])) % mod;
    printf("%d\n", ans);
    return 0;
}

