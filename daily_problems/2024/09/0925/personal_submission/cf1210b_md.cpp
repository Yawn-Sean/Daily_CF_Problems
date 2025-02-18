// 0925
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> as(n);
    std::vector<int> bs(n);
    std::unordered_map<i64, int> cnt;

    for (auto& a : as) {
        std::cin >> a;
        cnt[a]++;
    }

    for (auto& b : bs) {
        std::cin >> b;
    }

    i64 ret = 0;
    std::vector<int> visited(n, 0);
    for (auto[k, v] : cnt) {
        if (v > 1) {
            for (int i = 0; i < n; ++i) {
                if (visited[i]) {
                    continue;
                }

                if ((as[i] & k) == as[i]) {
                    visited[i] = 1;
                    ret += bs[i];
                }
            }
        }
    }
    std::cout << ret << '\n';

    return 0;
}