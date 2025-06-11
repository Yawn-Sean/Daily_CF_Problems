#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

constexpr int N = 2E5;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    int M = 0;
    for (int i = 0; i < n; ++ i) {
        std::cin >> a[i];
        M = std::max(M, a[i]);
    }

    std::vector<int> acc(M + 1);

    for (int x : a)
        ++ acc[x];

    for (int i = 0; i < M; ++ i)        
        acc[i + 1] += acc[i];

    std::ranges::sort(a);
    a.resize(std::unique(a.begin(), a.end()) - a.begin());

    i64 res = 0;

    for (int x : a) {
        i64 s = 0;
        for (int i = x; i <= M; i += x) {
            s += 1LL * i * (acc[std::min(M, i + x - 1)] - acc[i - 1]);
        }
        res = std::max(res, s);
    }

    std::cout << res << '\n';
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