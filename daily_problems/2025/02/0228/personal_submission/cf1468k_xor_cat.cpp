#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

auto go(std::array<int, 2> cur, char c) {
    auto ret = cur;
    if (c == 'L') {
        ret[0]--;
    }
    if (c == 'R') {
        ret[0]++;
    }
    if (c == 'U') {
        ret[1]++;
    }
    if (c == 'D') {
        ret[1]--;
    }
    return ret;
}

void solve() {
    std::string s;
    std::cin >> s;

    std::array<int, 2> now = {0, 0};
    auto e = now;
    for (auto &c : s) {
        now = go(now, c);
        std::array<int, 2> cur = {0, 0};
        for (auto &c : s) {
            auto next = go(cur, c);
            if (next == now) {
                next = cur;
            }
            cur = next;
        }
        if (cur == e) {
            std::cout << now[0] << " " << now[1] << "\n";
            return;
        }
    }
    std::cout << 0 << " " << 0 << "\n";
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
