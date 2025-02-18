#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using real = long double;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    
    int x1, y1, r1;
    std::cin >> x1 >> y1 >> r1;
    
    int x2, y2, r2;
    std::cin >> x2 >> y2 >> r2;

    if (r1 > r2) std::swap(r1, r2);

    real dr = std::abs(r1 - r2);
    real dist = std::hypotl(x1 - x2, y1 - y2);

    if (dist > r1 + r2) {
        std::cout << (dist - (r1 + r2)) / 2 << "\n";
    } else if (r2 - r1 > dist) {
        std::cout << (r2 - dist - r1) / 2 << "\n";
    } else {
        std::cout << 0 << "\n";
    }
    
    return 0;
}
