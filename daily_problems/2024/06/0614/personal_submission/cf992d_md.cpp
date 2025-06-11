// 0614
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(nums));
    
    auto sum_cap = std::accumulate(begin(nums), end(nums), 0ll) * k;

    std::vector<int> next(n);
    std::iota(begin(next), end(next), 0);
    for (int i = n - 2; i >= 0; --i) {
        if (nums[i] == 1) {
            next[i] = next[i + 1];
        }
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        size_t cur_idx = i;
        i64 sum = 0;
        i64 product = 1;
        while (cur_idx < n) {
            // nums[cur_idx] != 1
            if (next[cur_idx] == cur_idx) {
                if (product > sum_cap / nums[cur_idx]) {
                    break;
                }

                sum += nums[cur_idx];
                product *= nums[cur_idx];
                if (sum * k == product) {
                    ++ret;
                }
                ++cur_idx;
            } else {
                // sum + one_cnt = product * k
                // product = k(x + sum) => x = product / k - sum => x >= 0 && x < one_cnt
                int one_cnt = next[cur_idx] - cur_idx;
                i64 x = product / k - sum;
                if (product % k == 0 && x > 0 && x <= one_cnt) {
                    ++ret;
                }

                sum += one_cnt;
                cur_idx = next[cur_idx];
            }
        }
    }

    std::cout << ret << '\n';

    return 0;
}