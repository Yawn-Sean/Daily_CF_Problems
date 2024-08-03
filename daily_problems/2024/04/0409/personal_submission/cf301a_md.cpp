#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int len = 2 * n - 1;
    vector<int> a(len);
    copy_n(istream_iterator<int>(std::cin), len, begin(a));

    int neg_cnt{};
    int min_abs = INT_MAX;
    for (auto val : a) {
        min_abs = min(min_abs, abs(val));
        if (val < 0) {
            ++neg_cnt;
        }
    }

    int sum = accumulate(begin(a), end(a), 0, [&](int&& acc, int val) { return move(acc) + abs(val); });
    if (neg_cnt % 2 == 0) {
        cout << sum << '\n';
    } else {
        cout << sum - (1 - n & 1) * 2 * min_abs << '\n';
    }

    return 0;
}