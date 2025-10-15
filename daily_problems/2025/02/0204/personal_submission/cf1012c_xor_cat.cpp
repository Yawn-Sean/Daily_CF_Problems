#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <typename T>
bool chmin(T &a, const T &b) {
    return b < a ? a = b, true : false;
}
template <typename T>
bool chmax(T &a, const T &b) {
    return b > a ? a = b, true : false;
}

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        if (i > 0) c[i] += std::max(0, a[i - 1] - a[i] + 1);
        if (i < n - 1) c[i] += std::max(0, a[i + 1] - a[i] + 1);
    }

    std::cout << std::ranges::min(c) << " ";

    std::vector<int> pre(n);
    std::vector f(n, std::vector<int>((n + 1) / 2));
    for (int i = 0; i < n; i++) {
        f[i][0] = c[i];
    }

    for (int j = 1; j < (n + 1) / 2; j++) {
        f[0][j] = f[1][j] = inf;
        pre[0] = inf;
        pre[1] = f[0][j - 1];
        for (int i = 2; i < n; i++) {
            pre[i] = pre[i - 1];
            chmin(pre[i], f[i - 1][j - 1]);
        }
        for (int i = 2; i < n; i++) {
            f[i][j] = std::min(pre[i - 2] + c[i],
                               f[i - 2][j - 1] + c[i] - std::max(0, a[i - 1] - std::max(a[i], a[i - 2]) + 1));
        }
        int ans = inf;
        for (int i = 0; i < n; i++) {
            chmin(ans, f[i][j]);
        }
        std::cout << ans << " ";
    }

    return 0;
}
