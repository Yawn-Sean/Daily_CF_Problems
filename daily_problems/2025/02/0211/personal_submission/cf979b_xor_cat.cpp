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

    std::string s[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> s[i];
    }

    std::array<int, 3> mx{};
    std::map<char, int> mp[3];
    for (int i = 0; i < 3; i++) {
        for (auto &c : s[i]) {
            mp[i][c]++;
        }
        for (auto &[_, x] : mp[i]) {
            chmax(mx[i], x);
        }
    }

    for (int i = 0; i < 3; i++) {
        int t = n;
        if (mx[i] == s[i].size()) {
            mx[i] = s[i].size() - (t == 1);
        } else if (mx[i] + t >= s[i].size()) {
            mx[i] = s[i].size();
        } else {
            mx[i] += t;
        }
    }

    int winner = std::ranges::max(mx);
    if (std::ranges::count(mx, winner) >= 2) {
        std::cout << "Draw\n";
    } else if (winner == mx[0]) {
        std::cout << "Kuro\n";
    } else if (winner == mx[1]) {
        std::cout << "Shiro\n";
    } else if (winner == mx[2]) {
        std::cout << "Katie\n";
    }

    return 0;
}
