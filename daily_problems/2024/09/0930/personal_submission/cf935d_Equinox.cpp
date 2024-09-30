#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

constexpr int P = 1'000'000'007;

int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % P)
        if (b & 1)
            res = 1LL * res * a % P;
    return res;
}

int frac(int n, int m) {
    return 1LL * power(n, P - 2) * m % P;
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> s1(n), s2(n);

    for (int i = 0; i < n; ++ i)
        std::cin >> s1[i];

    for (int i = 0; i < n; ++ i)
        std::cin >> s2[i];

    int ans = 0, eq = 1;

    int inv = frac(m, 1);

    for (int i = 0; i < n; ++ i) {
        if (s1[i] && s2[i] && s1[i] != s2[i]) {
            ans += eq * (s1[i] > s2[i]);
            if (ans >= P)
                ans -= P;
            break;
        } else if (s1[i] == 0 && s2[i] == 0) {
            ans += frac(2 * m, m - 1);
            if (ans >= P)
                ans -= P;
            eq = 1LL * eq * inv % P;
        } else if (s1[i] == 0 & s2[i]){
            ans += frac(m, m - s2[i]);
            if (ans >= P) 
                ans -= P;
            eq = 1LL * eq * inv % P;
        } else if (s1[i] && s2[i] == 0){
            ans += frac(m, s1[i] - 1);
            if (ans >= P)
                ans -= P;
            eq = 1LL * eq * inv % P;
        }
    }

    std::cout << ans << '\n';
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