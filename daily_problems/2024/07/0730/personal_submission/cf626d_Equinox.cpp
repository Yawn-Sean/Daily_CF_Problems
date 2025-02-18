#include <bits/stdc++.h>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++ i) std::cin >> a[i];

    std::vector<int> cnt(5000);
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < i; ++ j)
            ++ cnt[abs(a[i] - a[j])];


    std::vector<i64> acc(5000);
    for (int i = 0; i < 5000; ++ i)
        for (int j = 0; j + i < 5000; ++ j)
            acc[i + j] += cnt[i] * cnt[j];

    for (int i = 1; i < 5000; ++ i)
        acc[i] += acc[i - 1];

    i64 tot = 0;

    for (int i = 0; i < 4999; ++ i)
        tot += acc[i] * cnt[i + 1];
    
    std::cout << std::setprecision(12) << 1.0 * tot / pow(1.0 * (n - 1) * n / 2, 3);
}

auto init_ = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif     

    int t = 1;
    // std::cin >> t;
    while (t --)
        solve();

    return 0;
}