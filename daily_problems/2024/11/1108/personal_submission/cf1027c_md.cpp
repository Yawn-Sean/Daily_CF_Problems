// 1108
#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        freq[x]++;
    }


    // (2x + 2y) ^ 2 / (x * y)
    // (4x^2 + 4y^2 + 4xy) / xy
    // 4 x / y + 4 y / x + 4 (1)

    std::vector<int> edges;
    for (auto [k, v] : freq) {
        if (v >= 4) {
            std::cout << k << " " << k << " " << k << " " << k << std::endl;
            return;
        }
        
        if (v >= 2) {
            edges.push_back(k);
        }
    }

    std::sort(edges.begin(), edges.end());
    int x = 0;
    int y = 1;
    for (int i = 1; i < ssize(edges); ++i) {
        int ny = edges[i];
        int nx = edges[i - 1];

        // compare y / x vs ny / nx where y > x and ny > nx
        // if ny / nx < y / x => ny * x < nx * y
        if (ny * x < nx * y) {
            x = nx;
            y = ny;
        }
    }

    std::cout << x << " " << x << " " << y << " " << y << std::endl;

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