#include <bits/stdc++.h>
#include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1'000'000'007;
constexpr int P = 2333;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for (int i = 0; i < n; ++ i) std::cin >> a[i],-- a[i];

    int m;
    std::cin >> m;

    int f = 0;
    std::vector<bool> vis(n);

    for (int i = 0; i < n; ++ i) {
        if (a[i] == i) {
            ++ f;
            vis[i] = true;
        }
        if (vis[i]) continue;
        
        int t = i;
        while (!vis[t]) {
            vis[t] = true, t = a[t];
        } 
        ++ f;
    }    

    f = n - f;
    
    int t = m - f;
    std::cout << abs(t) << '\n';

    if (t > 0) {
        while (t --) {
            vis.assign(n, false);
            int x = -1, y = -1;
            for (int i = 0; i < n; ++ i) {
                if (!vis[i]) {
                    if (x == -1) x = i;
                    else if(y == -1) {
                        y = i;
                        break;
                    }
                    int j = i;
                    while (!vis[j])
                        vis[j] = true, j = a[j];
                }
            }
            std::swap(a[x], a[y]);
            std::cout << x + 1 << ' ' << y + 1 << ' ';
        }
    }
    else if (t < 0) {
        while (t ++) {
            vis.assign(n, false);
            for (int i = 0; i < n; ++ i) {
                if (a[i] != i) {
                    int x = i, y = n;
                    while (!vis[i]) {
                        vis[i] = true;
                        if (i != x) y = std::min(i, y);
                        i = a[i];
                    }
                    std::swap(a[x], a[y]);
                    std::cout << x + 1 << ' ' << y + 1 << ' ';
                    break;
                }
            }

        }
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