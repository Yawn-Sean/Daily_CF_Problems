#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using real = long double;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(10);
    
    int n, k;
    i64 l, v1, v2;
    std::cin >> n >> l >> v1 >> v2 >> k;

    i64 x = (n + k - 1) / k;
    std::cout << (real)1 * l / v2 * (2 * v2 * (x - 1) + v1 + v2) / (2 * v1 * (x - 1) + v1 + v2) << "\n";
    
    return 0;
}
