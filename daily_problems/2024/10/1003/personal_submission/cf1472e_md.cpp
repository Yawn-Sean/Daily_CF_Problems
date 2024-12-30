// 1003
#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::tuple<int, int, int>> people(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (x > y) {
            std::swap(x, y);
        }
        people[i] = {x, y, i};
    }

    std::sort(begin(people), end(people), [](const auto& a, const auto& b) {
        auto[x1, y1, _] = a;
        auto[x2, y2, __] = b;
        if (x1 == x2) {
            return y1 > y2;
        }
        return x1 < x2;
    });

    std::vector<int> ret(n, -2);
    int lastH = INT_MAX;
    int lastIdx = -1;
    for (auto[w, h, idx] : people) {
        if (h > lastH) {
            ret[idx] = lastIdx;
        } else {
            lastH = h;
            lastIdx = idx;
        }
    }

    for (auto idx : ret) {
        std::cout << idx + 1 << ' ';
    }
    std::cout << '\n';
    return;
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