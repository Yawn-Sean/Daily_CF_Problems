#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> lmn(n, -1), rmn(n, n);
    std::vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty()) {
            if (a[stk.back()] < a[i]) {
               lmn[i] = stk.back();
               break; 
            }
            stk.pop_back();
        }
        stk.push_back(i);
    }
    stk.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty()) {
            if (a[stk.back()] < a[i]) {
                rmn[i] = stk.back();
                break;
            }
            stk.pop_back();
        }
        stk.push_back(i);
    }

    std::map<std::pair<int, int>, std::vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[{lmn[i], rmn[i]}].push_back(i);
    }

    int ans = 0;
    for (auto &[_, v] : mp) {
        auto [l, r] = _;
        l++, r--;
        // std::cout << "[" << l << ", " << r << "]: ";
        std::vector<int> sum(2);
        for (int i = 0; i <= v.size(); i++) {
            int s = 0;
            if (i == 0) {
                s = v[0] - l + 1;
            } else if (i == v.size()) {
                s = r - v.back() + 1;
            } else {
                s = v[i] - v[i - 1];
            }

            sum[i & 1] += s;
        }
        // int half = v.size() / 2, nhalf = v.size() - half;
        // std::cout << sum[0] << " " << sum[1] << " " << v.size() << ": " << sum[0] * sum[1] + half * (half - 1) / 2 + nhalf * (nhalf - 1) / 2 + v.size() << "\n";
        ans += sum[0] * sum[1];

        // std::cout << "\n";
    }
    std::cout << ans << "\n";

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
