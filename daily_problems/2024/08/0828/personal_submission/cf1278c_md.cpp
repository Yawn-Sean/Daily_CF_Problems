// 0828
#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> left(n), right(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> left[i];
    }
    
    for (int i = 0; i < n; ++i) {
        std::cin >> right[i];
    }
    
    std::vector<int> left_diff(n + 1, 0), right_diff(n + 1, 0);
    int ans = 2 * n;
    for (int i = 0; i < n; ++i) {
        left_diff[i + 1] = left_diff[i] + (left[i] == 1 ? 1 : -1);
        if (left_diff[i + 1] == 0) {
            ans = std::min(ans, 2 * n - (i + 1));
        }
    }

    std::map<int, int> right_pos;
    for (int i = n; i > 0; --i) {
        right_diff[i - 1] = right_diff[i] + (right[i - 1] == 1 ? 1 : -1);
        if (right_diff[i - 1] == 0) {
            ans = std::min(ans, n + (i - 1));
        }
        right_pos[right_diff[i - 1]] = i - 1;
    }

    for (int i = n; i >= 0; --i) {
        if (right_pos.contains(-left_diff[i])) {
            ans = std::min(ans, n - i + right_pos[-left_diff[i]]);
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}