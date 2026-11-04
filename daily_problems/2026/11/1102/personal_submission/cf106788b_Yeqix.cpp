#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<u64> f(k + 1);
    for (int i = 1; i <= k; i++) {
        f[i] = rng() * rng();
    }

    u64 res = 0;
    for (int i = 1; i <= k; i++) {
        res += f[i] * i;
    }

    vector<int> p(k + 1);
    rgs::iota(p, 0);

    i64 ans = 0;
    map<u64, i64> mp;
    mp[res]++;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        res -= l * f[p[l]] + r * f[p[r]];
        swap(p[l], p[r]);
        res += l * f[p[l]] + r * f[p[r]];
        ans += mp[res];
        mp[res]++;
    }

    cout << ans;
    return 0;
}