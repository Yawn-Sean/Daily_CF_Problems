#include <bits/stdc++.h>
 
using i64 = long long;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, mod;
    std::cin >> a >> b >> mod;
    for (int i = 0; i <= a && i < mod; i++) {
        int rem = i * 1000000000LL % mod;
        if ((mod - rem) % mod > b) {
            std::cout << 1 << ' ' << std::setw(9) << std::setfill('0') << i << '\n';
            return 0;
        }
    }    
    std::cout << 2;
 
    return 0;
}
