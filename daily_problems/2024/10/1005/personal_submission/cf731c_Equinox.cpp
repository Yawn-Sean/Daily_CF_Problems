#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int h, q;
    std::cin >> h >> q;

    std::map<i64, int> diff;

    diff[1LL << h - 1] = diff[1 << h] = 0;

    for (int i = 0; i < q; ++ i) {
        int idx, ans;
        i64 l, r;
        std::cin >> idx >> l >> r >> ans;
        ++ r;
        l <<= h - idx;
        r <<= h - idx;

        if (ans) {
            ++ diff[l];
            -- diff[r];
        } else {
            ++ diff[1LL << h - 1];
            -- diff[l];
            ++ diff[r];
            -- diff[1LL << h];
        }
    }

    int cur = 0;
    i64 last = 1LL << h - 1, cnt = 0, st = 0;
    for (auto &[k, v] : diff) {
        if (cur == q) {
            cnt += k - last;
            st = last;
        }
        last = k;
        cur += v;
    }

    if (cnt == 0) std::cout << "Game cheated!\n";
    else if(cnt == 1) std::cout << st << '\n';
    else std::cout << "Data not sufficient!\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef DEBUG
    int cur = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}