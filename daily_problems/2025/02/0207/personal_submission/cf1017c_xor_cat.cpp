#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    int c = sqrt(n);

    while (n > 0) {
        for (int i = n - c + 1; i <= n; i++) {
            if (i > 0) {
                std::cout << i << " ";
            }
        }
        n -= c;
    }
    
    return 0;
}
