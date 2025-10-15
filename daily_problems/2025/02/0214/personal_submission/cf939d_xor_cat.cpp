#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    DSU dsu(26);
    std::vector<std::pair<char, char>> ans;
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        int y = dsu.find(t[i] - 'a');
        if (dsu.merge(x, y)) {
            ans.push_back({'a' + char(x), 'a' + char(y)});
        }
    }

    std::cout << ans.size() << "\n";
    for (auto &[u, v] : ans) {
        std::cout << u << " " << v << "\n";
    }

    return 0;
}
