#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; scanf("%lld", &n);
    set<long long> ans;
    for (long long K = (1LL << 60) - 1; ; K >>= 1) {
        __int128 t = (__int128) (2 * K - 1) * (2 * K - 1) + 8 * n;
        __int128 s = round(sqrt((long double) t));
        if (s * s == t) {
            __int128 x = s - (2 * K - 1);
            if (x % 2 == 0 && x / 2 % 2 == 1) ans.insert(x / 2 * (K + 1));
        }
        if (K == 0) break;
    }
    if (ans.empty()) printf("-1\n");
    else for (long long x : ans) printf("%lld\n", x);
    return 0;
}
