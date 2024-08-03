#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::vector<std::array<int, 4>> a4s(n);
    for (auto& a4 : a4s)
        for (int& x : a4)
            std::cin >> x;
    std::vector<std::array<int, 4>> pre(n), suf(n);
    std::array<int, 4> cur = { -inf,-inf,inf,inf };
    for (int i = 0;i < n;++i) {
        cur[0] = std::max(cur[0], a4s[i][0]);
        cur[1] = std::max(cur[1], a4s[i][1]);
        cur[2] = std::min(cur[2], a4s[i][2]);
        cur[3] = std::min(cur[3], a4s[i][3]);
        pre[i] = cur;
    }
    cur = { -inf,-inf,inf,inf };
    for (int i = n - 1;i >= 0;--i) {
        cur[0] = std::max(cur[0], a4s[i][0]);
        cur[1] = std::max(cur[1], a4s[i][1]);
        cur[2] = std::min(cur[2], a4s[i][2]);
        cur[3] = std::min(cur[3], a4s[i][3]);
        suf[i] = cur;
    }
    for (int i = 0;i < n;++i) {
        cur = { -inf,-inf,inf,inf };
        if (i) {
            cur[0] = std::max(cur[0], pre[i - 1][0]);
            cur[1] = std::max(cur[1], pre[i - 1][1]);
            cur[2] = std::min(cur[2], pre[i - 1][2]);
            cur[3] = std::min(cur[3], pre[i - 1][3]);
        }
        if (i != n - 1) {
            cur[0] = std::max(cur[0], suf[i + 1][0]);
            cur[1] = std::max(cur[1], suf[i + 1][1]);
            cur[2] = std::min(cur[2], suf[i + 1][2]);
            cur[3] = std::min(cur[3], suf[i + 1][3]);
        }
        if (cur[0] <= cur[2] && cur[1] <= cur[3]) {
            std::cout << cur[0] << ' ' << cur[1] << '\n';
            return 0;
        }
    }
    return 0;
}