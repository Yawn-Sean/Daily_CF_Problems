#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

std::vector<int> Z(std::vector<int> s) {
    int n = s.size();
    std::vector<int> z(n + 1);
    z[0] = n;
    for (int i = 1, j = 1; i < n; i++) {
        z[i] = std::max(0LL, std::min(j + z[j] - i, z[i - j]));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > j + z[j]) {
            j = i;
        }
    }
    return z;
}


void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto z = Z(a);
    int mx = -1;
    for (int i = 2; i <= n; i++) {
        int d = i - 1;
        if (z[d] != n - d) {
            mx = d;
        }
        std::cout << mx << " \n"[i == n];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
