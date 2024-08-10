// 0704
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(a));
    std::vector<int> b(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(b));
    b.emplace_back(-1);

    std::vector<int> used(n + 1, 0);
    int a_idx = n - 1;
    int b_idx = n - 1;
    while (b_idx >= 0) {
        if (a_idx >= 0 && b_idx >= 0 && a[a_idx] == b[b_idx]) {
            --a_idx;
            --b_idx;
        } else if (b[b_idx] == b[b_idx + 1]) {
            ++used[b[b_idx]];
            b_idx--;
        } else if (used[a[a_idx]] > 0) {
            --used[a[a_idx]];
            --a_idx;
        } else {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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