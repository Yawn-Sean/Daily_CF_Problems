#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, k, p, x, y;
    std::cin >> n >> k >> p >> x >> y;

    std::vector<i64> a(k);
    int cnt = 0, mid = (n + 1) / 2;
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
        cnt += (a[i] >= y);
    }

    i64 sum = std::reduce(a.begin(), a.end());

    i64 need = std::max<i64>(0, (n + 1) / 2 - cnt);
    if (n - k < need) {
        std::cout << -1 << "\n";
        return 0;
    }

    if (need * y + (n - k - need) + sum > x) {
        std::cout << -1 << "\n";
        return 0;
    }

    for (int i = 0; i < need; i++) {
        std::cout << y << " ";
    }
    for (int i = 0; i < n - k - need; i++) {
        std::cout << 1 << " ";
    }

    return 0;
}
