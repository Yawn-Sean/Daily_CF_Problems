#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> path(n);
        vector<int> indeg(n, 0);

        for (int i = 0; i < m; i ++) {
            vector<int> vals(n);
            for (auto &v: vals) cin >> v, v --;
            for (int i = 2; i < n; i ++) {
                path[vals[i - 1]].emplace_back(vals[i]);
                indeg[vals[i]] ++;
            }
        }

        vector<int> stk;
        for (int i = 0; i < n; i ++) {
            if (indeg[i] == 0) {
                stk.emplace_back(i);
            }
        }

        int cnt = 0;
        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back(), cnt ++;
            for (auto &v: path[u]) {
                indeg[v] --;
                if (indeg[v] == 0) stk.emplace_back(v);
            }
        }

        cout << (cnt == n ? "YES" : "NO") << '\n';
    }

    return 0;
}
