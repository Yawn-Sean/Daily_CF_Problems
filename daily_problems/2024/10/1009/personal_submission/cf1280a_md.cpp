// 1009
#include <bits/stdc++.h>

using i64 = long long;
constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    const auto len = ssize(s);
    std::vector<int> values(1e6 + 1, 0);
    std::transform(begin(s), end(s), begin(values), [](char c) { return c - '0'; });

    int ret = len;
    int curIdx = len;
    for (int i = 0; i < n; ++i) {
        ret += (values[i] - 1) * (ret - i - 1) % MOD;
        ret %= MOD;

        const auto times = values[i];
        const auto prevEnd = curIdx;
        for (int extra = 0; extra < times - 1 && curIdx < n; ++extra) {
            for (int j = i + 1; j < prevEnd && curIdx < n; ++j) {
                values[curIdx++] = values[j];
            }
        }
    }

    std::cout << (ret + MOD) % MOD << '\n';
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}