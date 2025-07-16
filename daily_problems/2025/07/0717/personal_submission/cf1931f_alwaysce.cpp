#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        set<pair<int, int>> seen;
        vector<int> deg(n, 0);
        vector<vector<int>> path(n);
        for (int j = 0; j < k; j++) {
            vector<int> perm(n);
            for (auto &x : perm) {
                cin >> x;
            }

            for (int i = 1; i + 1 < n; i++) {
                int x = perm[i], y = perm[i + 1];
                x--; y--;
                
                if (seen.find({x, y}) != seen.end()) {
                    continue;
                }
                path[x].push_back(y);
                seen.insert({x, y});
                ++deg[y];
            }
        }

        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.push(i);
                ++cnt;
            }
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto y : path[x]) {
                --deg[y];
                if (deg[y] == 0) {
                    q.push(y);
                    ++cnt;
                }
            }
        }

        if (cnt == n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
