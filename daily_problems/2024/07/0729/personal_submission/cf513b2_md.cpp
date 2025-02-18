// 0729
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, m;
    std::cin >> n >> m;
    m--;

    std::vector<int> ret(n);
    int left = 0;
    int right = n - 1;

    for (int i = 1; i < n; ++i) {
        if (m >> (n - i - 1) & 1) {
            ret[right--] = i;
        } else {
            ret[left++] = i;
        }
    }
    ret[left] = n;

    for (auto x : ret) {
        std::cout << x << ' ';
    }
    return 0;
}