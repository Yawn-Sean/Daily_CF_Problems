// 0518
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<vector<int>> graph(n);
    vector<int> node_cnt(n, 1);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        graph[p].push_back(i);
        node_cnt[p] = 0;
    }

    auto dfs = [&](auto self, int cur) -> void {
        for (auto nxt : graph[cur]) {
            self(self, nxt);
            node_cnt[cur] += node_cnt[nxt];
        }
    };

    dfs(dfs, 0);

    sort(begin(node_cnt), end(node_cnt));
    for (int i = 0; i < n; ++i) {
        cout << node_cnt[i] << " \n"[i == n - 1];
    }

    return 0;
}