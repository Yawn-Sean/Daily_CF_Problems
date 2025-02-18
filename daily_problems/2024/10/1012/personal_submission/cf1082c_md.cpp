// 1012
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<i64>> groups(m + 1);
    for (int i = 0; i < n; ++i) {
        int s, r;
        std::cin >> s >> r;
        groups[s].push_back(r);
    }

    std::vector<i64> sums(n + 1);
    for (auto&& group : groups) {
        std::sort(begin(group), end(group), std::greater{});
        i64 acc = 0;
        for (int i = 0; i < ssize(group); ++i) {
            acc += group[i];
            if (acc > 0) {
                sums[i + 1] += acc;
            } else {
                break;
            }
        }
    }
    
    std::cout << *max_element(begin(sums), end(sums)) << '\n';

    return 0;
}