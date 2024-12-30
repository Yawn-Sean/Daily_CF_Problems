// 0703
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    int min_len = n;
    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        --r; --l;
        int len = r - l + 1;
        min_len = std::min(len, min_len);
    }

    std::cout << min_len << '\n';
    std::vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cout << i % min_len << ' ';
    }
    std::cout << '\n';

    return 0;
}  