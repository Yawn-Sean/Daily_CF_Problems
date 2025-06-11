// 0702
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;
constexpr int MOD = 998244353;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::vector<int> b(k);
    std::map<int, int> idx_a;
    std::map<int, int> idx_b;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        idx_a[a[i]] = i;
    }

    for (int i = 0; i < k; ++i) {
        std::cin >> b[i];
        idx_b[b[i]] = i + 1; // default 0 for numbers not in b
    }

    std::vector<int> choices(n, 1);
    for (int i = 0; i < n; ++i) {
        bool remove_left{ i > 0 && (!idx_b.contains(a[i - 1]) || idx_b[a[i - 1]] < idx_b[a[i]]) };
        bool remove_right{ i + 1 < n && (!idx_b.contains(a[i + 1]) || idx_b[a[i + 1]] < idx_b[a[i]]) };
        choices[i] = remove_left + remove_right;
    }

    int ret = 1;
    for (auto val : b) {
        ret = (ret * choices[idx_a[val]]) % MOD;
    }

    std::cout << ret << '\n';
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