#include <bits/stdc++.h>

using namespace std;
int lnz(unsigned long long x) {
    if (x == 0) {
        return 1;
    }
    return 64 - __builtin_clzll(x);
}

int main() {
    long long n, l, r;
    scanf("%lld%lld%lld", &n, &l, &r);
    function<int(long long, long long)> dfs = [&] (long long x, long long k) {
        long long y = x / 2;
        if (y) {
            if (k <= (1LL << lnz(y)) - 1) {
                return dfs(y, k);
            }
            if (k > (1LL << lnz(y))) {
                return dfs(y, k - (1LL << lnz(y)));
            }
        }
        return static_cast<int>(x % 2);
    };
    int ans = 0;
    for (long long i = l; i <= r; i++) {
        ans += dfs(n, i);
    }
    printf("%d\n", ans);
    return 0;
}

