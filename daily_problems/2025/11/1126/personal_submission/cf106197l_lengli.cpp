#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int read_int() {
    int x;
    if (!(std::cin >> x)) {
        return 0; 
    }
    return x;
}

void solve() {
    int n = read_int();

    std::vector<std::vector<int>> ans(n, std::vector<int>(n, 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ans[i][j] += 2;
        }
    }

    for (int i = n % 2; i < n; ++i) {
        ans[n - 1][i] += 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << ans[i][j];
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t = read_int();

    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}
