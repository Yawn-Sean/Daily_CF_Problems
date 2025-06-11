// 1028
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> buildings(n);

    i64 ret = 0;
    for (auto&[v1, v2] : buildings) {
        std::cin >> v1 >> v2;
        if (v1 > v2) {
            std::swap(v1, v2);
        }
        ret = std::max(ret, 1ll * v1 * v2);
    } 

    std::sort(buildings.begin(), buildings.end(), std::greater<>());

    int maxV2 = 0;
    for (auto[v1, v2] : buildings) {
        ret = std::max(ret, 2ll * v1 * std::min(maxV2, v2));
        maxV2 = std::max(maxV2, v2);
    }

    std::cout << ret / 2 << "." << ret % 2 * 5 << std::endl;
    return 0;
} 