#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using u64 = unsigned long long;

#define debug     std::cerr << "[line : "<< __LINE__ << ": " << "func : " << __FUNCTION__ << "] "  


void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 2, std::vector<int>(m + 2, 0));
    int mi = 1000;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> g[i][j];
            if(mi > g[i][j]) mi = g[i][j];
        }
    }
    
    std::vector<std::string> ans;
    for(int i = 0; i < mi; i++) {
        if(n > m) {
            for(int j = 1; j <= m; j++) {
                ans.push_back("col " + std::to_string(j));
            }
        } else {
            for(int j = 1; j <= n; j++) {
                ans.push_back("row " + std::to_string(j));
            }
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            g[i][j] -= mi;
    
    
    for(int i = 1; i <= n; i++) {
        int l = 0, r = 1000;
        auto check = [&](int x) {
            for(int j = 1; j <= m; j++) {
                if(g[i][j] < x) return false; 
            }
            return true;
        };

        while(l < r - 1) {
            int mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        for(int j = 0; j < l; j++) {
            ans.push_back("row " + std::to_string(i));
        }
        for(int j = 1; j <= m; j++) g[i][j] -= l;
    }

    for(int i = 1; i <= m; i++) {
        int l = 0, r = 1000;
        auto check = [&](int x) {
            for(int j = 1; j <= n; j++) {
                if(g[j][i] < x) return false; 
            }
            return true;
        };

        while(l < r - 1) {
            int mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        for(int j = 0; j < l; j++) {
            ans.push_back("col " + std::to_string(i));
        }
        for(int j = 1; j <= n; j++) g[j][i] -= l;
    }
    for(int i = 1; i <= n; i++) {
        if(count(g[i].begin() + 1, g[i].begin() + 1 + m, 0) != m) {
            std::cout << -1 << "\n";
            return;
        }
    }

    std::cout << ans.size() << "\n";
    for(auto s : ans) std::cout << s << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;  
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}
