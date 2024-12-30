// 0513
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    vector<i64> nums(n);
    copy_n(istream_iterator<i64>(std::cin), n, begin(nums));

    std::unordered_map<i64, i64, custom_hash> cnts[11];
    for (auto num : nums) {
        const auto len = size(std::to_string(num));
        cnts[len][num % k]++;
    }

    i64 ret = 0;
    for (auto num : nums) {
        auto cur = num;
        const auto len = size(std::to_string(num));
        for (int d = 1; d <= 10; ++d) {
            cur = cur * 10ll % k;
            auto target = (k - cur) % k;
            if (cnts[d].contains(target)) {
                ret += cnts[d][target];
            }
            
            if (len == d && (cur + num % k) % k == 0) {
                --ret;
            }
        }
    }

    cout << ret << endl;

    return 0;
}