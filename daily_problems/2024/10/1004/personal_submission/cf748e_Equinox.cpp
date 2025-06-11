#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    int M = 0;
    for (int i = 0; i < n; ++ i) {
        std::cin >> a[i];
        M = std::max(M, a[i]);
    }

    std::vector<i64> cnt(M + 1);
    for (int x : a)
        ++ cnt[x];

    i64 cur = 0;

    for (int i = M; i; -- i) {
        cur += cnt[i];

        if (i * 2 + 1 <= M) {
            cur += cnt[2 * i + 1];
            cnt[i] += cnt[i * 2 + 1];
            cnt[i + 1] += cnt[i * 2 + 1];
        }

        if (i * 2 <= M) {
            cur += cnt[i * 2];
            cnt[i] += cnt[i * 2] * 2;
        }

        if (cur >= k) {
            std::cout << i << '\n';
            return;
        }
    }

    std::cout << "-1\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef DEBUG
    int cur = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}