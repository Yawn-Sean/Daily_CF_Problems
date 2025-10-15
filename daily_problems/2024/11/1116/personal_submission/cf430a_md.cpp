// 1116
#include <bits/stdc++.h>
#include <ranges>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> points(n);
    for (auto& x : points) {
        std::cin >> x;
    }

    std::vector<int> ids(n);
    std::iota(begin(ids), end(ids), 0);
    std::ranges::sort(ids, [&](int i, int j) {
        return points[i] < points[j];
    });

    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[ids[i]] = i % 2;
    }

    for (auto x : ans) {
        std::cout << x << ' ';
    }

    return 0;
}