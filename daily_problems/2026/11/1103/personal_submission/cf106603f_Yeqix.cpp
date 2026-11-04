#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<i64> val(n + 1);
    for (int i = 1; i <= n; i++) {
        i64 p, x;
        cin >> p >> x;
        val[p] = max(val[p], x);
    }

    i64 mx = 0;
    vector<i64> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        if (val[i] > mx) {
            mx = val[i];
            for (int j = i; j <= n; j++) {
                dp[j] = max(dp[j], dp[j - i] + mx);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    return 0;
}