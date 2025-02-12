#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

using Z = DynModInt<0>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    Z a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        a += b;
        std::swap(a, b);
    }
    
    std::cout << a * power(Z(2), n).inv() << "\n";
    
    return 0;
}
