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

    int n, m;
    std::cin >> n >> m;

    std::vector<int> d(m + 2);
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        d[l]++;
        d[r + 1]--;
    }

    std::vector<int> a(m + 2);
    for (int i = 1; i <= m + 1; i++) {
        a[i] = a[i - 1] + d[i];
    }

    std::vector<int> f;
    std::vector<int> l(m + 2), r(m + 2);
    for (int i = 1; i <= m; i++) {
        if (f.empty() || a[i] >= f.back()) {
            f.push_back(a[i]);
        } else {
            *std::ranges::upper_bound(f, a[i]) = a[i];
        }
        l[i] = f.size();
    }

    f.clear();

    for (int i = m; i >= 1; i--) {
        if (f.empty() || a[i] >= f.back()) {
            f.push_back(a[i]);
        } else {
            *std::ranges::upper_bound(f, a[i]) = a[i];
        }
        r[i] = f.size();
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        chmax(ans, l[i] + r[i + 1]);
    }
    std::cout << ans << "\n";

    return 0;
}
