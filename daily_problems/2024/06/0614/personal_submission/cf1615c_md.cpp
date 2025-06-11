// 0614
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    std::string  a, b;
    std::cin >> a >> b;
    
    auto cnt_1_in_a = std::ranges::count(a, '1');
    auto cnt_1_in_b = std::ranges::count(b, '1');
    int diff_cnt = 0;
    for (int i = 0; i < n; ++i) {
        diff_cnt += (a[i] != b[i]);
    }

    int ret = std::numeric_limits<int>::max();
    if (cnt_1_in_a == cnt_1_in_b) {
        ret = diff_cnt;
    }

    if (1 + n - cnt_1_in_a == cnt_1_in_b) {
        // There must exist at least one '1' in a
        ret = std::min(ret, n - (diff_cnt - 2) - 2);
    }

    if (ret == std::numeric_limits<int>::max()) {
        std::cout << "-1\n";
    } else {
        std::cout << ret << "\n";
    }
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