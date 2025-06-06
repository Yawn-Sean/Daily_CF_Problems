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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::ranges::sort(a);

    std::vector<int> f(n + 1);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + 20;
        auto it1 = std::lower_bound(a.begin() + 1, a.begin() + i + 1, a[i] - 89) -
                   a.begin() - 1;
        chmin(f[i], f[it1] + 50);
        auto it2 = std::lower_bound(a.begin() + 1, a.begin() + i + 1, a[i] - 1439) -
                   a.begin() - 1;
        chmin(f[i], f[it2] + 120);
    }

    for (int i = 1; i <= n; i++) {
        std::cout << f[i] - f[i - 1] << "\n";
    }

    return 0;
}
