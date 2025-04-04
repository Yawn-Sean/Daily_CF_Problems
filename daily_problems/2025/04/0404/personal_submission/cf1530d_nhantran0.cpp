/**
 * https://codeforces.com/problemset/problem/1530/D
 * D. Secret Santa
 * Solver: nhant
 * 2025-04-04 22:48:21
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n + 1);
    vector<vector<int>> from(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        from[b[i]].push_back(i);
    }
    int k = n;
    for (int i = 1; i <= n; i++) {
        if (from[i].size() > 1) { // in deg > 1
            int sawKeep = false;
            for (int j = 0, m = (int)from[i].size(); j < m; j++) {
                int u = from[i][j];
                // prioritize breaking edges of a "path" to create at least 1 path (from a circle) or 2 paths (from a path)
                if (!sawKeep && (from[u].size() == 0 || j == m - 1)) {
                    sawKeep = true;
                } else {
                    b[u] = 0;
                    k--;
                }
            }
        }
    }
    vector<pair<int,int>> paths;
    for (int i = 1; i <= n; i++) {
        if (from[i].size() == 0) {
            int end = i;
            while (b[end] != 0) end = b[end];
            // BEWARE that this causes inf loop. Find the test case input!
            // if (paths.size() > 0) {
            //     b[paths[paths.size() - 1].second] = i;
            // }
            paths.push_back({i, end});
        }
    }
    for (int i = 0, z = (int) paths.size(); i < z; i++) {
        int j = i == z - 1 ? 0 : i + 1;
        b[paths[i].second] = paths[j].first;
    }
    cout << k << '\n';
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
