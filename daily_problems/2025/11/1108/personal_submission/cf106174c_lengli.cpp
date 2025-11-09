#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long digits_sum_upto(long long x) {
    if (x <= 0) return 0;
    __int128 start = 1;
    long long d = 1;
    __int128 ans = 0;
    for (int i = 0; i < 18; ++i) {
        if (start > x) break;
        __int128 take = start * 9;
        __int128 rem = (__int128)x - start + 1;
        if (take > rem) take = rem;
        ans += take * d;
        start *= 10;
        ++d;
    }
    return (long long)ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    if (!(cin >> n >> k)) return 0;

    long long l = 1, r = (long long)1e18;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        long long left = digits_sum_upto(mid + n - 1) - digits_sum_upto(mid - 1);
        if (left < k) l = mid + 1;
        else r = mid - 1;
    }

    if (digits_sum_upto(l + n - 1) - digits_sum_upto(l - 1) == k) {
        cout << l << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
