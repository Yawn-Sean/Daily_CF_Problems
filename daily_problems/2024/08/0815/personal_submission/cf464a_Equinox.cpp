#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf = 1E9;

int query(const std::string &s) {
    std::cout << "? " << s << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n;
    std::cin >> n;

    int t0 = query(std::string(n, '1'));
    int t1 = query("0" + std::string(n - 1, '1'));

    if (t1 == t0 + 1) // s[0] = 1
    {  
        int lo = 1, hi = n;
        
        while (lo < hi) {
            int x = lo + hi >> 1;
            if (query("1" + std::string(lo - 1, '1') + std::string(x - lo + 1, '0') + std::string(n - x - 1, '1'))
                == t0 + x - lo + 1) {
                lo = x + 1;
            }
            else
                hi = x;
        }

        std::cout << "! " << lo + 1 << ' ' << 1 << std::endl;
    }
    else    // s[0] = 0 
    {
        int lo = 1, hi = n;
        
        while (lo < hi) {
            int x = lo + hi >> 1;
            if (query("0" + std::string(lo - 1, '1') + std::string(x - lo + 1, '0') + std::string(n - x - 1, '1'))
                + x - lo + 1 == t0 - 1) {
                lo = x + 1;
            }
            else
                hi = x;
        }

        std::cout << "! " << 1 << ' ' << lo + 1 << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}