#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using u64 = unsigned long long;

void solve() {
    i64 a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    bool ok = 1;
    if(a * c * e >= b * d * f && a && b && c && d && e && f) {
        ok = false;
    } else {
        if (d == 0) ok = false;
        else {
            if(c != 0) {
                if(b == 0) ok = false;
                else {
                    if(a != 0) {
                        if(f == 0) ok = false;
                        else {
                            
                        }
                    }
                }
            } 
        }
    }

    std::cout << (ok ? "Ron" : "Hermione") << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;  
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}
