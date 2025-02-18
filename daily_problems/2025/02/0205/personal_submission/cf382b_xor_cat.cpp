#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, w, x, c;
    std::cin >> a >> b >> w >> x >> c;

    if (c <= a) {
        std::cout << 0 << "\n";
        return 0;
    }

    std::cout << ((i64(c - a) * x - b + (w - x - 1)) / (w - x) + c - a) << "\n";
    
    return 0;
}
