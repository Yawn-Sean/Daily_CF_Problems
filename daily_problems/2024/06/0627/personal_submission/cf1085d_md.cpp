// 0627
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, s;
    std::cin >> n >> s;
    std::vector<int> degree(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;
        ++degree[a];
        ++degree[b];
    }

    int leaves = count(begin(degree), end(degree), 1);
    std::cout << std::fixed << std::setprecision(15) << 2.0 * s / leaves << '\n';

    return 0;
}