#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> l(n), r(n), idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    for (int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i];
    }

    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return l[i] < l[j] || (l[i] == l[j] && r[i] > r[j]);
    });
    for (int i = 0; i < n; i++) {
        if (i && r[idx[i-1]] >= r[idx[i]]) {
            std::cout << idx[i] + 1 << '\n';
            return 0;
        }
        if (i > 1 && l[idx[i]] <= r[idx[i-2]] + 1) {
            std::cout << idx[i-1] + 1 << '\n';
            return 0;
        }
    }
    std::cout << -1 << '\n';
    return 0;
}
