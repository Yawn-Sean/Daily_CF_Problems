// 0905
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    std::vector<int> cnt(1 << 14, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        cnt[nums[i]]++;
    }

    i64 ret = 0;
    if (k == 0) {
        for (int i = 0; i < (1 << 14); ++i) {
            ret += 1ll * cnt[i] * (cnt[i] - 1) / 2;
        }
        std::cout << ret << '\n';
    } else {
        std::vector<int> vals;
        for (int i = 0; i < (1 << 14); ++i) {
            if (__builtin_popcount(i) == k) {
                vals.push_back(i);
            }
        }
        
        for (int mask = 0; mask < (1 << 14); ++mask) {
            for (auto val : vals) {
                ret += 1ll * cnt[mask] * cnt[mask ^ val];
            }
        }
        std::cout << ret / 2 << '\n';
    }

    return 0;
}