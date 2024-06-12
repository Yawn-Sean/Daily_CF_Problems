// 0611
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d;
    std::cin >> n >> d;
    std::vector<int> nums(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(nums));
    
    int sum_min {0};
    int sum_max {0};
    int deposit {0};
    for (auto num : nums) {
        if (num == 0) {
            sum_min = std::max(0, sum_min);
            if (sum_max < 0) {
                sum_max = d;
                ++deposit;
            }
        } else {
            sum_min += num;
            sum_max += num;
            
            if (sum_min > d) {
                std::cout << -1 << '\n';
                return 0;
            }

            sum_max = std::min(sum_max, d);
        }
    }

    std::cout << deposit << '\n';

    return 0;
}