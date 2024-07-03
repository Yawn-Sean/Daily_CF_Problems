// 0701
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> ret(n, std::vector<int>(4));
    int cur_odd = 1;
    int cur_even = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (__gcd(cur_even, cur_odd) != 1) {
                cur_even += 2;
            }
            ret[i][j] = cur_odd * k;
            cur_odd += 2;
        }
        ret[i][3] = k * cur_even;
        cur_even += 2;
    }

    std::cout << (cur_odd - 2) * k << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << ret[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}