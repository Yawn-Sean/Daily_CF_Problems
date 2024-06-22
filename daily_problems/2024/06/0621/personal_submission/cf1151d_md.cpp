// 0621
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<i64, i64>> people(n);
    for (int i = 0; i < n; ++i) {
        i64 a, b;
        std::cin >> a >> b;
        people[i] = {a - b, n * b - a};
    }

    std::sort(begin(people), end(people), std::greater<>());

    std::cout << std::accumulate(begin(people), end(people), 0ll, [j = 1](i64 acc, auto p) mutable {
        return acc + p.first * (j++) + p.second;
    }) << '\n';

    return 0;
}