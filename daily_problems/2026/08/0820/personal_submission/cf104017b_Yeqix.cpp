#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<i64, 2>> f(n * n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            i64 x;
            cin >> x;
            f[x] = {i, j};
        }
    }

    i64 ans = 0;
    vector<i64> r(n + 1), c(n + 1);
    for (int i = 1; i <= n * n; i++) {
        auto [x, y] = f[i];
        ans += c[y] * (n - r[x] - 1);
        ans += r[x] * (n - c[y] - 1);

        r[x]++, c[y]++;
    }

    cout << ans / 2;
    return 0;
}