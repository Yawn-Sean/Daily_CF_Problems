#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    std::vector<int> id(N + 1);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        id[a[i]] = i;
    }

    std::vector<int> sum(N + 1);
    for (int i = 0; i < N; i++) {
        sum[i + 1] = sum[i] + a[i];
    }

    int ans = (1 + N) * N / 2 - N - 1;
    for (int i = 1; i <= N; i++) {
        // std::cout << id[i] << ": ";
        // std::cout << sum[id[i]] << ", " << sum[N] - sum[id[i] + 1] << "\n";
        ans = std::max(ans, std::max({sum[id[i]], sum[N] - sum[id[i] + 1]}) - i);
    }
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
