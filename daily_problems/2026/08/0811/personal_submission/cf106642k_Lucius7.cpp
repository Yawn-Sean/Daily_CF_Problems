#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::vector<int> r(n), c(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                r[i]++;
                c[j]++;
            }
        }
    }

    std::vector<int> vr(n), vc(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                vr[i] += c[j] - 1;
                vc[j] += r[i] - 1;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                sum += (r[i] - 1) * (c[j] - 1);
            }
        }
    }

    int mx = sum, cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '0') {
                int res = sum + r[i] * c[j] + vr[i] + vc[j];
                if (res > mx) {
                    mx = res;
                    cnt = 1;
                } else if (res == mx) {
                    cnt++;
                }
                
            }
        }
    }
    std::cout << mx << " " << cnt << "\n";
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
