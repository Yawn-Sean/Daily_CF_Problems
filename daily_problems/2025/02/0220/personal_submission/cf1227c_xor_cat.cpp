#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::string t;
    for (int i = 0; i < k - 1; i++) {
        t += "()";
    }
    t += std::string(n / 2 - (k - 1), '(');
    t += std::string(n / 2 - (k - 1), ')');

    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int j = i;
            while (s[j] != t[i]) {
                j++;
            }
            ans.emplace_back(i, j);
            std::reverse(s.begin() + i, s.begin() + j + 1);
        }
    }

    std::cout << ans.size() << "\n";
    for (auto &[l, r] : ans) {
        std::cout << l + 1 << " " << r + 1 << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
       solve();
    }

    return 0;
}
