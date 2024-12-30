// 0507
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int inf = numeric_limits<int>::max();
    int n, m;
    std::cin >> n >> m;
    vector<int> to_move(n, 0);
    vector<int> min_dis(n, inf);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a, --b;
        ++to_move[a];
        min_dis[a] = min(min_dis[a], (b - a + n) % n);
    }

    vector<int> ret(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (min_dis[j] == inf) {
                continue;
            }
            int offset = (j - i + n) % n;
            int extra = (to_move[j] - 1) * n;
            int last_run = min_dis[j];
            ret[i] = max(ret[i], offset + extra + last_run);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ret[i] << " \n"[i == n - 1];
    }

    return 0;
}