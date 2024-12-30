// 0903
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    if (k % 2 == 0) {
        std::cout << "-1\n";
        return 0;
    }

    std::vector<int> ans(n);
    std::iota(begin(ans), end(ans), 1);

    auto merge = [&](auto&& self, int l, int r) {
        if (k == 0 || l + 1 == r) {
            return;
        }

        int m = (l + r) / 2;
        std::swap(ans[m], ans[m - 1]);
        k -= 2;
        self(self, l, m);
        self(self, m, r);
    };

    --k;
    merge(merge, 0, n);

    if (k != 0) {
        std::cout << "-1\n";
    } else {
        for (auto i = 0; i < size(ans); ++i) {
            std::cout << ans[i] << " \n"[i + 1 == size(ans)];
        }
    }

    return 0;
}