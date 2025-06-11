// 0719
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::vector<int> next_diff_pos(n, n);
    for (int i = n - 2; i >= 0; --i) {
        if (nums[i] == nums[i + 1]) {
            next_diff_pos[i] = next_diff_pos[i + 1];
        } else {
            next_diff_pos[i] = i + 1;
        }
    }

    std::vector<std::tuple<int, int, int>> queries;
    while (m--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        --l; --r;
        bool found = false;
        for (int i = l; i <= r; i = next_diff_pos[i]) {
            if (nums[i] != x) {
                found = true;
                std::cout << i + 1 << '\n';
                break;
            }
        }
        if (!found) {
            std::cout << "-1\n";
        }
    }

    return 0;
}