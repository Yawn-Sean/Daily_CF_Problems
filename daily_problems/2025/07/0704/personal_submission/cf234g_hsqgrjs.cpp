#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using u64 = unsigned long long;
#define MultiCases()   int t = 1; std::cin >> t; while(t--) 
#define SingleCase()   int t = 1; while(t--) 
std::vector<int> a[2], b[2];
void solve() {
    int n;
    std::vector<std::vector<int>> ans;
    std::cin >> n;
    int k = std::ceil(log(n) / log(2));
    for(int i = 1; i <= n; i++) {
        if(i <= n / 2) a[0].push_back(i);
        else a[1].push_back(i);
    }
    std::cout << k << "\n";
    std::cout << a[0].size() << " ";
    for(int i = 0; i < a[0].size(); i++) {
        std::cout << a[0][i] << " \n"[i == a[0].size() - 1];
    }
    for(int i = 1; i < k; i++) {
        b[0] = std::move(a[0]);
        b[1] = std::move(a[1]);
        // a[0].clear(), a[1].clear();
        for(int j = 0; j < b[0].size(); j++) {
            if(j & 1) {
                a[1].push_back(b[0][j]);
            } else {
                a[0].push_back(b[0][j]);
            }
        }
        for(int j = 0; j < b[1].size(); j++) {
            if(j & 1) {
                a[1].push_back(b[1][j]);
            } else {
                a[0].push_back(b[1][j]);
            }
        }
        std::cout << a[0].size() << " ";
        for(int j = 0; j < a[0].size(); j++) {
            std::cout << a[0][j] << " \n"[j == a[0].size() - 1];
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    SingleCase()
        solve();
    return 0;
}
