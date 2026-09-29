#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        if (i < n) {
            std::cin >> a[i];
        } else {
            a[i] = a[i - n];
        }
    }

    int sz = (n + 1) / 2;
    
    int mx = -1E15;
    std::deque<int> v;
    int sum = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        v.push_back(a[i]);
        sum += a[i];
        if (v.size() > sz) {
            sum -= v.front();
            v.pop_front();
        }
        
        if (v.size() == sz) {
            mx = std::max(mx, sum);
        }
    }
    v.clear();
    sum = 0;
    for (int i = 1; i < 2 * n; i += 2) {
        v.push_back(a[i]);
        sum += a[i];
        if (v.size() > sz) {
            sum -= v.front();
            v.pop_front();
        }
        if (v.size() == sz) {
            mx = std::max(mx, sum);
        }
    }
    std::cout << mx << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
