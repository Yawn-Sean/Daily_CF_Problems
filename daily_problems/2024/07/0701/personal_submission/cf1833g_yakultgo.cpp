#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> g[n + 1];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    if (n % 3 != 0) {
        cout << -1 << endl;
        return;
    }
    int sze[n + 1][3];
    bool flag = true;
    vector<int> edge;
    function<void(int, int)> dfs = [&](int x, int fa) -> void {
        sze[x][0] = sze[x][1] = sze[x][2] = 0;
        for (auto &i : g[x]) {
            if (i.first == fa) continue;
            dfs(i.first, x);
            if (sze[i.first][0] >= 1) {
                edge.push_back(i.second);
            }
            sze[x][1] += sze[i.first][1];
            sze[x][2] += sze[i.first][2];
        }
        int cnt = sze[x][1] + sze[x][2] * 2;
        if (cnt > 2) {
            flag = false;
            return;
        }
        if (sze[x][1] == 1) {
            sze[x][2] = 1;
            sze[x][1] = 0;
        } else if (sze[x][2] == 1 || sze[x][1] == 2) {
            sze[x][1] = sze[x][2] = 0;
            sze[x][0] = 1;
        } else {
            sze[x][1] = 1;
        }
    };
    dfs(1, 0);
    if (!flag)
        cout << -1 << endl;
    else {
        cout << edge.size() << endl;
        for (auto &i : edge) {
            cout << i << " ";
        }
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}