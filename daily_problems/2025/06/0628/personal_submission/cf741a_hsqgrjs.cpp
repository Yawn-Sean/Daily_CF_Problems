#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
i64 lcm(i64 x, i64 y) {
    return  x * y / std::gcd(x, y);
}
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> c(n);
    std::vector<int> in(n, 0);
    for(auto &x : c) {
        std::cin >> x;
        --x;
        in[x]++;
    }

    for(int i = 0; i < n; i++) if(in[i] == 0) {
        std::cout << -1 << "\n";
        return;
    }

    int ans = 1;
    for(int i = 0; i < n; i++) {
        int q1 = c[i], q2 = c[q1], cnt = 1;
        while(q2 != i) {
            q1 = c[q1];
            q2 = c[c[q2]];
            cnt++;
        }
        // std::cerr << cnt << "\n";
        ans = lcm(ans, cnt);
    }
    std::cout << ans << "\n";
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
