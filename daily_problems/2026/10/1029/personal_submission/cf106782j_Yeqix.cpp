#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n, c;
    cin >> n >> c;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    i64 ans = 0, sum = 0;
    for (int i = n; i >= 1; i--) {
        if (sum) {
            ans += 2;
        }
        ans += (sum + a[i]) / c * i * 2;
        sum = (sum + a[i]) % c;
    }

    cout << ans + (sum + c - 1) / c * 2;
    return 0;
}