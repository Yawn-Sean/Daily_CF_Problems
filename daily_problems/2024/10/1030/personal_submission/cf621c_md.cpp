// 1030
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, p;
    std::cin >> n >> p;
    std::vector<double> probs(n);
    for (int i = 0; i < n; ++i) {
        int left, right;
        std::cin >> left >> right;
        probs[i] = 1.0 * (right / p - (left - 1) / p) / (right - left + 1);
    }

    double ret = 0;
    for (int i = 0; i < n; ++i) {
        auto next = (i + 1) % n;
        ret += probs[i] + probs[next] - probs[i] * probs[next];
    }

    std::cout << std::fixed << std::setprecision(10) << ret * 2000 << '\n';

    return 0;
}