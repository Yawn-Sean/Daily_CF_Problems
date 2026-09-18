#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    
    std::vector<int> a(s.size());
    for (int i = 0; i < s.size(); i++) {
        a[i] = s[i] - '0';
    }

    std::vector<int> pre(s.size() + 1);
    for (int i = 0; i < s.size(); i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    int sum = std::accumulate(a.begin(), a.end(), 0LL);

    int d = 0;
    std::vector<int> cnt(10);
    for (int i = 0; i < 1E6; i++) {
        d = d + sum;
        cnt[d % 10]++;
        d /= 10;
    }

    int u = 0, v = 0;
    for (int i = 0; i <= 9; i++) {
        // std::cout << cnt[i] << " \n"[i == 9];
        if (cnt[i] > v) {
            u = i;
            v = cnt[i];
        }
    }
    std::cout << u << "\n";

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
