#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> win(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        win[i] = {u - 1, v - 1};
    }
    int l = 0, r = m;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        // 建图
        vector<vector<int>> g(n);
        vector<int> left(n, 0);
        for (int i = 0; i < mid; ++i) {
            g[win[i].first].push_back(win[i].second);
            left[win[i].second]++;
        }
        // 拓扑排序
        vector<int> stk;
        for (int i = 0; i < n; ++i) {
            if (left[i] == 0) {
                stk.push_back(i);
            }
        }
        bool flag = false;
        while (!stk.empty()) {
            if (stk.size() > 1) {  // 说明同时有几个人的排名不能确定，尝试扩大二分范围
                flag = true;
                break;
            }
            int u = stk.back();
            stk.pop_back();
            for (int v : g[u]) {
                left[v]--;
                if (left[v] == 0) {
                    stk.push_back(v);
                }
            }
        }
        if (flag) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l <= m ? l : -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cout << solve();
    return 0;
}