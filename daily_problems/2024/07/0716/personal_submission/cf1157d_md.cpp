// 0716
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, k;
    std::cin >> n >> k;
    i64 sum = k * (k + 1) / 2;
    if (sum > n) {
        std::cout << "NO\n";
        return 0;
    }

    n -= sum;
    i64 rem = n % k;
    i64 addition = n / k;
    std::vector<i64> ans(k);
    std::iota(ans.begin(), ans.end(), 1);
    for (int i = 0; i < k; ++i) {
        ans[i] += addition;
    }

    for (int i = k - 1; i >= 0 && rem > 0; --i) {
        if (ans[i] == 2 && ans[i - 1] == 1) {
            break;
        }
        ++ans[i];
        --rem;
    }

    // suppose rem > 0
    // ans = [1, 2] => [1, 2+1], No result for n, k
    // ans = [1, 2, 3] => [1, 2, 3+2], No result for n, k
    // ans = [1, 2, 3, 4] => [1, 2, 3+1, 4+2], Satisfy for k >= 4
    ans[k - 1] += rem;

    bool fail = false;
    for (int i = 1; i < k; ++i) {
        if (ans[i] <= ans[i - 1] || ans[i] > 2 * ans[i - 1]) {
            fail = true;
            break;
        }
    }

    if (fail) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        for (int i = 0; i < k; ++i) {
            std::cout << ans[i] << " \n"[i == k - 1];
        }
    }
    return 0;
}