#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> path(n);

    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<int> dis(n, -1), dis1(n, -1), stk;

    for (int i = 0; i < n; i ++) {
        if (path[i].size() == 1) {
            stk.emplace_back(i);
            dis[i] = 0;

            while (!stk.empty()) {
                int u = stk.back();
                stk.pop_back();
                for (auto &v: path[u]) {
                    if (dis[v] == -1) {
                        dis[v] = dis[u] + 1;
                        stk.emplace_back(v);
                    }
                }
            }

            int nd = max_element(dis.begin(), dis.end()) - dis.begin();
            stk.emplace_back(nd);
            dis1[nd] = 0;

            while (!stk.empty()) {
                int u = stk.back();
                stk.pop_back();
                for (auto &v: path[u]) {
                    if (dis1[v] == -1) {
                        dis1[v] = dis1[u] + 1;
                        stk.emplace_back(v);
                    }
                }
            }

            int rt = -1;

            for (int i = 0; i < n; i ++) {
                if (dis[i] == k && dis1[i] == k) {
                    rt = i;
                }
            }

            if (rt == -1) return cout << "No", 0;

            vector<int> to_center(n, -1);
            stk.emplace_back(rt);
            to_center[rt] = 0;

            while (!stk.empty()) {
                int u = stk.back();
                stk.pop_back();
                for (auto &v: path[u]) {
                    if (to_center[v] == -1) {
                        to_center[v] = to_center[u] + 1;
                        stk.emplace_back(v);
                    }
                }
            }

            if (path[rt].size() < 3) return cout << "No", 0;

            for (int i = 0; i < n; i ++) {
                if (path[i].size() == 1) {
                    if (to_center[i] != k)
                        return cout << "No", 0;
                }
                else if (i != rt && path[i].size() <= 3)
                    return cout << "No", 0;
            }
            cout << "Yes";

            return 0;
        }
    }

    cout << "No";
    return 0;
}