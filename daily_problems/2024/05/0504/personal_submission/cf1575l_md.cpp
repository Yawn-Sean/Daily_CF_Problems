// 0504
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<pair<int, int>> nums;
    // i - val_i <= j - val_j; val_i < val_j
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        if (i - val >= 0) {
            nums.emplace_back(i - val, val);
        }
    }

    sort(begin(nums), end(nums));

    vector<int> lis;
    for (auto[_, val] : nums) {
        auto it = lower_bound(begin(lis), end(lis), val);
        if (it == end(lis)) {
            lis.push_back(val);
        } else {
            *it = val;
        }
    }

    std::cout << ssize(lis) << endl;

    return 0;
}