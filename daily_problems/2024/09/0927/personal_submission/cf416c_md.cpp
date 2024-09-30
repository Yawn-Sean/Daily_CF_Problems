// 0927
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::tuple<int, int, int>> groups(n);
    for (int i = 0; i < n; ++i) {
        int c, p;
        std::cin >> c >> p;
        groups[i] = {c, p, i + 1};
    }

    int k;
    std::cin >> k;
    std::vector<std::pair<int, int>> maxp(k);
    for (int i = 0; i < k; ++i) {
        int cap;
        std::cin >> cap;
        maxp[i] = {cap, i + 1};
    }

    std::sort(begin(groups), end(groups));
    std::sort(begin(maxp), end(maxp));

    std::priority_queue<std::pair<int, int>> pq;
    int cur_group = 0, tot = 0, cnt = 0;
    std::vector<int> ans(n + 1, -1);

    for (auto[maxcap, id_table] : maxp) {
        while (cur_group < n && std::get<0>(groups[cur_group]) <= maxcap) {
            pq.push({std::get<1>(groups[cur_group]), std::get<2>(groups[cur_group])});
            ++cur_group;
        }

        if (!empty(pq)) {
            auto[cost, id_group] = pq.top();
            pq.pop();
            tot += cost;
            ++cnt;
            ans[id_group] = id_table;
        }
    }

    std::cout << cnt << ' ' << tot << '\n';
    for (int i = 1; i <= n; ++i) {
        if (ans[i] != -1) {
            std::cout << i << ' ' << ans[i] << '\n';
        }
    }

    return 0;
}