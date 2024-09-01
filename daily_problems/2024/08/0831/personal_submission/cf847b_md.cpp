
// 0831
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::vector<int> min_values;
    std::vector<std::vector<int>> results;
    for (auto i : nums) {
        if (size(min_values) == 0) {
            min_values.push_back(-i);
            results.push_back({i});
        } else {
            auto it = std::lower_bound(begin(min_values), end(min_values), -i);
            if (it == end(min_values)) {
                min_values.push_back(-i);
                results.push_back({i});
            } else {
                auto idx = it - begin(min_values);
                min_values[idx] = -i;
                results[idx].push_back(i);
            }
        }
    }

    for (const auto& v : results) {
        for (int i = 0; i < size(v); ++i) {
            std::cout << v[i] << " \n"[i == ssize(v) - 1];
        }
    }
    
    return 0;
}
