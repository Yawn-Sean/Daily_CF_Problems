#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1'000'000'007;

void solve() {
    int n, T;
    std::cin >> n >> T;

    std::vector<int> a(n), t(n);
    for (int i = 0; i < n; ++ i)
        std::cin >> a[i] >> t[i];

    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);

    std::ranges::sort(id, [&](int i, int j) -> bool{
        return t[i] < t[j];
    });

    auto check = [&](int x) -> bool{
        int res = 0, s = 0;
        for (int i : id) {
            if (a[i] >= x && s + t[i] <= T)
                s += t[i], ++ res;
            if (res == x) return true;
        }
        return false;
    };

    int lo = 0, hi = n;

    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
        if (check(x))
            lo = x;
        else
            hi = x - 1;
    }

    std::cout << lo << '\n' << lo << '\n';

    int res = 0, s = 0;
    for (int i : id) {
        if (a[i] >= lo && s + t[i] <= T) {
            s += t[i], ++ res;
            std::cout << i + 1 << " \n"[res == lo];
        }
        if (res == lo) break;
    }    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}