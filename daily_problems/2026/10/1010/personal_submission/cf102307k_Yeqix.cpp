#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int N = 1e5;
i64 dp[N + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    dp[3] = 2;
    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i - 1] + (i % 3 <= 1);
    }

    while (n--) {
        i64 x;
        cin >> x;
        cout << dp[x] << "\n";
    }
    return 0;
}