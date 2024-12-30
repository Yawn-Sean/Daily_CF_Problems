// 1102
#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 MOD = 1e9 + 7;

i64 modpow(i64 base, i64 exp, i64 mod) {
    i64 ret = 1;
    while (exp) {
        if (exp & 1) {
            ret = ret * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return ret % MOD;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::string valstr;
    std::cin >> valstr;
    std::vector<int> nums(n);
    std::transform(begin(valstr), end(valstr), begin(nums), [](char c) { return c - '0'; });

    std::vector<int> prefix(n + 1);
    std::partial_sum(begin(nums), end(nums), begin(prefix) + 1);
    
    auto sum = [&](int onecnt, int zerocnt) {
        auto full = modpow(2, onecnt + zerocnt, MOD);
        auto base = modpow(2, zerocnt, MOD);
        return (full + MOD - base) % MOD;
    };

    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        --l, --r;
        int onecnt = prefix[r + 1] - prefix[l];
        int zerocnt = r - l + 1 - onecnt;

        std::cout << sum(onecnt, zerocnt) << '\n';
    }


    return 0;
}