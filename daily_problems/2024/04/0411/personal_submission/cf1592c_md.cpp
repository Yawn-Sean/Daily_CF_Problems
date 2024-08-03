#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, k;
    std::cin >> n >> k;
    vector<int> a(n);
    copy_n(istream_iterator<int>(std::cin), n, begin(a));
    vector<vector<int>> tree(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    auto xor_sum = accumulate(begin(a), end(a), 0, bit_xor<int>());
    if (xor_sum == 0) {
        std::cout << "YES\n";
        return;
    }

    if (k == 2) {
        std::cout << "NO\n";
        return;
    }

    int cnt = 0;
    auto dfs = [&](auto self, int u, int p) -> int {
        auto sum = a[u];
        for (auto v : tree[u]) {
            if (v == p) {
                continue;
            }
            sum ^= self(self, v, u);
        }

        if (sum == xor_sum) {
            ++cnt;
            return 0;
        }
        return sum;
    };

    auto comp_sum = dfs(dfs, 0, -1);
    if (comp_sum == 0 && cnt >= 3) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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