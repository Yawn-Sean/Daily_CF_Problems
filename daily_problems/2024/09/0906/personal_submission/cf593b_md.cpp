// 09061
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x1, x2;
    std::cin >> n >> x1 >> x2;

    std::vector<std::pair<i64, i64>> lines(n);
    for (int i = 0; i < n; ++i) {
        i64 ki, bi;
        std::cin >> ki >> bi;
        lines[i] = {ki * x1 + bi, ki * x2 + bi};
    }

    std::sort(begin(lines), end(lines));

    for (int i = 1; i < n; ++i) {
        if (lines[i].second < lines[i - 1].second) {
            std::cout << "YES\n";
            return 0;
        }
    }
    std::cout << "NO\n";

    return 0;
}