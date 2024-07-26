// 0706
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<i64> nums(n);
    std::copy_n(std::istream_iterator<i64>(std::cin), n, begin(nums));

    std::sort(begin(nums), end(nums));
    
    std::vector<i64> acc(n + 1);
    std::partial_sum(begin(nums), end(nums), next(begin(acc)));
    int max_cnt = 0;
    i64 min_num = nums.back() + 1;
    for (int i = 0; i < n; ++i) {
        int l = 0;
        int r = i;
        auto cando = [&](int mid) {
            return nums[i] * (1ll + i - mid) - (acc[i + 1] - acc[mid]) <= k;
        };
        while (l + 1 < r) {
            auto mid = (l + r) / 2;
            if (cando(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }

        if (cando(l)) {
            if (max_cnt < i - l + 1) {
                max_cnt = i - l + 1;
                min_num = nums[i];
            }
        } else if (cando(r)) {
            if (max_cnt < i - r + 1) {
                max_cnt = i - r + 1;
                min_num = nums[i];
            }
        }
    }

    std::cout << max_cnt << ' ' << min_num << '\n';

    return 0;
}