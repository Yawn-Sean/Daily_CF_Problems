#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> l(m);
    for(auto& x : l) std::cin >> x;
    int t = l[0];
    std::set<int> mm;
    std::vector<int> a(n + 1, 0);
    for(int i = 1; i < m; i++) {
        int s = l[i];
        if(s > t) {
            if(a[t] != 0 && a[t] != s - t) {
                std::cout << -1 << "\n";
                return;
            } else {
                a[t] = s - t;
                // mm.insert(s - t);
            }
        } else {
            if(a[t] != 0 && a[t] != s - t + n) {
                std::cout << -1 << "\n";
                return;
            } else {
                a[t] = s - t + n;
            }
        }
        t = l[i];
    }
    bool mp[n + 1] = {0};
    for(int i = 1; i <= n; i++) {
        if(a[i]) {
            mp[a[i]] = 1;
        }
    }
    int j = 1;
    for(int i = 1; i <= n; i++) {
        if(!a[i]) {
            while(mp[j])++j;
            mp[j] = 1;
            a[i] = j;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(mm.find(a[i]) != mm.end()) {
            std::cout << -1 << "\n";
            return;
        } else {
            mm.insert(a[i]);
        }
    }

    for(int i = 1; i <= n; i++) {
        std::cout << a[i] << " \n"[i == n];
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;  
    while (t--)
        solve();
    return 0;
}
