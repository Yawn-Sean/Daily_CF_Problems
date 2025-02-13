#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    i64 dx = x2 - x1 + 1;
    i64 dy = y2 - y1 + 1;

    std::cout << dx * (dy + 1) / 2 - (dx - 1) / 2 << "\n";

    return 0;
}
