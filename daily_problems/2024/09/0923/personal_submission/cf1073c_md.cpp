// 0923
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string operations;
    std::cin >> operations;
    int x, y;
    std::cin >> x >> y;
    
    if ((abs(x) + abs(y) > n) || (x + y - n) % 2 != 0) {
        std::cout << -1;
        return 0;
    }
    
    std::vector<int> xs(n + 1), ys(n + 1);
    for (int i = 0; i < n; ++i) {
        int dx = 0;
        int dy = 0;
        if (operations[i] == 'U') {
            dy = 1;
        } else if (operations[i] == 'D') {
            dy = -1;
        } else if (operations[i] == 'L') {
            dx = -1;
        } else if (operations[i] == 'R') {
            dx = 1;
        }
        xs[i + 1] = xs[i] + dx;
        ys[i + 1] = ys[i] + dy;
    }

    // modify [l, r] can reach
    auto canReach = [&](int l, int r) -> bool {
        int requiredX = abs(xs[l] + xs[n] - xs[r] - x);
        int requiredY = abs(ys[l] + ys[n] - ys[r] - y);
        if (requiredX + requiredY > r - l) {
            return false;
        }
        return true;
    };

    int l = 0;
    int ret = n + 1;
    for (int r = 0; r <= n; ++r) {
        while (canReach(l, r)) {
            ret = std::min(ret, r - l);
            l++;
        }
    }

    std::cout << ret << '\n';

    return 0;
}