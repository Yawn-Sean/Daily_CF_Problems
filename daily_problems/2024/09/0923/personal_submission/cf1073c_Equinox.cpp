#include <bits/stdc++.h>

#define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int x, y;
    std::cin >> x >> y;

    if (abs(x) + abs(y) > n || (x + y - n) % 2) {
        std::cout << -1;
        return;
    }

    std::unordered_map<char, std::pair<int, int>> dir;
    dir['U'] = {0, 1};
    dir['D'] = {0, -1};
    dir['R'] = {1, 0};
    dir['L'] = {-1, 0};

    std::vector<int> acc_x(n + 1), acc_y(n + 1);

    for (int i = 0; i < n; ++ i) {
        acc_x[i + 1] = acc_x[i] + dir[s[i]].first;
        acc_y[i + 1] = acc_y[i] + dir[s[i]].second;
    }

    auto check = [&](int l, int r) -> bool {
        return abs(acc_x[l] + acc_x[n] - acc_x[r] - x) + abs(acc_y[l] + acc_y[n] - acc_y[r] - y) > r - l;
    };

    int res = n;

    for (int i = 0, j = 0; i < n; ) {
        while (j < n && check(i, j)) ++ j;
        if(check(i, j)) break;
        res = std::min(res, j - i);
        ++ i;
    }

    std::cout << res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}