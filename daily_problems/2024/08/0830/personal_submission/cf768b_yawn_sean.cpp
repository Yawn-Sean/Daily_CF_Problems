#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

long long solve (long long n, long long l, long long r) {
    if (!n) return 0;
    if (n == 1) return 1;
    long long v = (1ll << (63 - __builtin_clzll(n))) - 1;
    long long ans = 0;
    if (l < v) ans += solve(n / 2, l, min(r, v - 1));
    if (l <= v && v <= r) ans += n & 1;
    if (r > v) ans += solve(n / 2, max(l - v - 1, 0ll), r - v - 1);
    return ans;
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, l, r;
    cin >> n >> l >> r;
    l --, r --;

    cout << solve(n, l, r);

    return 0;
}