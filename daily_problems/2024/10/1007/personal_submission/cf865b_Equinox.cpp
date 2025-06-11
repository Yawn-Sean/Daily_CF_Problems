#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

/*
    最多多买一个披萨

    如果买多了，最多调整 1->2 或者 2->1
    不会同时 1<->2

    不管调谁，都是调代价最小的
*/

void solve() {
    int n, S;
    std::cin >> n >> S;

    std::vector<int> s(n), a(n), b(n);

    i64 cnt1 = 0, cnt2 = 0;
    i64 ans = 0;

    std::vector<int> g1, g2;

    for (int i = 0; i < n; ++ i) {
        std::cin >> s[i] >> a[i] >> b[i];
        if (a[i] > b[i]) {
            g1.push_back(i);
            cnt1 += s[i];
            ans += 1LL * s[i] * a[i];
        } else {
            g2.push_back(i);
            cnt2 += s[i];
            ans += 1LL * s[i] * b[i];
        }
    }

    if ((cnt1 + cnt2 + S - 1) / S == (cnt1 + S - 1) / S + (cnt2 + S - 1) / S) {
        std::cout << ans << '\n';
        return;
    }

    // std::cerr << ans << '\n';

    int to2 = cnt1 % S, to1 = cnt2 % S;
    i64 wto2 = 0, wto1 = 0;

    // std::cerr << cnt1 << ' ' << cnt2 << '\n';
    // std::cerr << to2 << ' ' << to1 << '\n';

    std::ranges::sort(g1, [&](int i, int j){
        return a[i] - b[i] < a[j] - b[j];
    });

    for (int i : g1) {
        int t = std::min(to2, s[i]);
        to2 -= t;
        wto2 += 1LL * t * (b[i] - a[i]);
    }

    std::ranges::sort(g2, [&](int i, int j){
        return b[i] - a[i] < b[j] - a[j];
    });

    for (int i : g2) {
        int t = std::min(to1, s[i]);
        to1 -= t;
        wto1 += 1LL * t * (a[i] - b[i]);
    }

    // std::cerr << wto1 << ' ' << wto2 << '\n';

    std::cout << ans + std::max(wto1, wto2) << '\n';
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