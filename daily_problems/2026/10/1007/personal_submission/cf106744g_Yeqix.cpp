#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n, k;
    cin >> n >> k;

    i64 sum = k * (1 + k) / 2, cnt = n / sum;
    n -= cnt * sum;
    vector<i64> ans(k + 1, cnt);
    for (int i = k; i >= 1; i--) {
        if (n >= i) {
            n -= i, ans[i]++;
        }
    }

    for (int i = 1; i <= k; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}