#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
using PIII = std::pair<int, PII>;
const int inf = 1e9 + 7, P = 1e9 + 7;

/*
    a * b = x * y
    a' * b' * x^2 = x * y
    a' * b' = y / x
*/


void solve() {
    int l, r, x, y;
    std::cin >> l >> r >> x >> y;
    int res = 0;
    if (y % x == 0)
        for (int i = 1, ed = y / x; i * i <= ed; ++ i) 
            if (ed % i == 0 && std::__gcd(i, ed / i) == 1) 
                if (l <= i * x && i * x <= r && l <= ed / i * x && ed / i * x <= r)
                    res += 1 + (i != ed / i);
        
    
    std::cout << res;
}


int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}