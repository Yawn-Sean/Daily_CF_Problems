// 0716 
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<double> probs(n);
    for (int i = 0; i < n; i++) {
        std::cin >> probs[i];
    }
    
    std::sort(begin(probs), end(probs), std::greater<double>());

    double p0 = 1.0;
    double p1 = 0.0;
    for (auto prob : probs) {
        p1 = p0 * prob + p1 * (1.0 - prob);
        p0 = p0 * (1.0 - prob);
        if (p1 > p0) {
            break;
        }
    }

    std::cout << std::fixed << std::setprecision(10) << p1 << '\n';

    return 0;
}