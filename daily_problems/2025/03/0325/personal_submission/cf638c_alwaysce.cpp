#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<int> us(n - 1), vs(n - 1);
    vector<vector<int>> path(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        us[i] = u;
        vs[i] = v;
        path[u].push_back(i);
        path[v].push_back(i);
    }

    vector<int> color(n - 1, -1);

    function<void(int)> dfs = [&](int u) {
        int used = -1;
        for (auto&eid: path[u]) {
            if (color[eid] != -1) {
                used = color[eid];
            }
        }

        int cur_color = 0;
        for (auto&eid: path[u]) {
            if (color[eid] == -1) {
                while (cur_color == used) {
                    cur_color++;
                }
                int v = us[eid] + vs[eid] - u;
                color[eid] = cur_color;
                cur_color++;
                dfs(v);
            }
        }
    };

    dfs(1);
    int ans = *max_element(color.begin(), color.end()) + 1;
    
    vector<vector<int>> ansL(ans);
    for (int i = 0; i < n - 1; i++) {
        ansL[color[i]].push_back(i);
    }

    cout << ans << '\n';
    for (int i = 0; i < ans; i++) {
        cout << ansL[i].size() << ' ';
        for (auto&x: ansL[i]) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
