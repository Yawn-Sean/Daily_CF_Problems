#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<int>> lsts(n, vector<int>(m));
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> lsts[i][j];
            max_val = max(max_val, lsts[i][j]); 
        }
    }

    if (n % 2 == 0) {
        vector<bool> vis(max_val + 1, false);
        bool first = true;
        for (int i = 0; i < n; ++i) {
            int head = lsts[i][0];
            if (vis[head]) continue;
            vis[head] = true;
            
            for (int x : lsts[i]) {
                if (!first) cout << ' ';
                cout << x;
                first = false;
            }
        }
        cout << '\n';
    } 
    else {
        vector<int> next_pos(max_val + 1, 0);
        vector<int> idxs(max_val + 1, 0);

        for (int i = 0; i < n; i++) {
            int head = lsts[i][0];
            idxs[head] = i;
            next_pos[head] = lsts[i][m / 2];
        }

        int cur = lsts[0][0];
        int mid = m / 2;
        bool first = true;

        for (int j = 0; j < n; j++) {
            int row_idx = idxs[cur];
            for (int k = 0; k < mid; k++) {
                if (!first) cout << ' ';
                cout << lsts[row_idx][k];
                first = false;
            }
            cur = next_pos[cur];
        }
        cout << '\n';
    }
}

int main() {
    // 极致 I/O 优化
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
