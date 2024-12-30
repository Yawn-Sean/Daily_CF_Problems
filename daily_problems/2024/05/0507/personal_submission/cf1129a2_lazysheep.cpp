#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n, std::vector<int>(2));
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        v[a][0]++;
        int d = (b - a + n) % n;
        v[a][1] = (v[a][1] != 0 ? std::min(d, v[a][1]) : d);     
    }
    for (int i = 0; i < n; i++) {
        int mxt = 0;
        for (int j = i; j < i + n; j++) {
            int k = j % n;
            if (!v[k][0])    continue;
            int t = (v[k][0] - 1) * n + (k - i + n) % n + v[k][1];
            mxt = std::max(mxt, t);
        }
        std::cout << mxt << " \n"[i == n - 1];
    }

    return 0;
}
