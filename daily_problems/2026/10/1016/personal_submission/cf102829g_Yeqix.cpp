#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int md = (int)1e9 + 7;
void add(int& a, int b) {
    a += b;
    if (a >= md) {
        a -= md;
    }
}

constexpr int N = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    vector<int> dp(N << 1 | 1);
    for (int i = 1; i <= n; i++) {
        vector<int> ndp(N << 1 | 1);
        for (int j = a[i]; j <= (N << 1); j++) {
            add(ndp[j - a[i]], dp[j]);
        }
        for (int j = 0; j + a[i] <= (N << 1); j++) {
            add(ndp[j + a[i]], dp[j]);
        }

        add(ndp[N - a[i]], 1), add(ndp[N + a[i]], 1);
        dp = move(ndp);
        add(ans, dp[N]);
    }

    cout << ans;
    return 0;
}