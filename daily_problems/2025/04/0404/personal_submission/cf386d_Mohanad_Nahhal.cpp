/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector start(3, 0);
    vector a(n + 1, vector(n + 1, ' '));
    for (int i = 0; i < 3; i ++) cin >> start[i];
    sort(start.begin(), start.end());

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) cin >> a[i][j];
    }

    vector dis(n + 1, vector(n + 1, vector(n + 1, 1000000)));
    vector lst(n + 1, vector(n + 1, vector(n + 1, vector<int>())));
    vector ans(n + 1, vector(n + 1, vector(n + 1, pair<int, int>())));
    dis[start[0]][start[1]][start[2]] = 0;
    queue<vector<int>> q;
    q.push(start);

    while (q.size()) {
        vector v = q.front();
        q.pop();

        for (int i = 0; i < 3; i ++) {
            int x = v[(i + 1) % 3], y = v[(i + 2) % 3];
            for (int z = 1; z <= n; z ++) {
                if (a[v[i]][z] == a[x][y] && z != v[i] && z != x && z != y) {
                    vector vv = {x, y, z};
                    sort(vv.begin(), vv.end());

                    if (dis[vv[0]][vv[1]][vv[2]] > dis[v[0]][v[1]][v[2]] + 1) {
                        dis[vv[0]][vv[1]][vv[2]] = dis[v[0]][v[1]][v[2]] + 1;
                        lst[vv[0]][vv[1]][vv[2]] = v;
                        ans[vv[0]][vv[1]][vv[2]] = {v[i], z};
                        q.push(vv);
                    }
                }
            }
        }
    }

    if (dis[1][2][3] != 1000000) {
        cout << dis[1][2][3] << endl;
        function<void(vector<int>)> dfs = [&] (vector<int> x) {
            if (x == start) return;
            dfs(lst[x[0]][x[1]][x[2]]);
            cout << ans[x[0]][x[1]][x[2]].first << ' ' << ans[x[0]][x[1]][x[2]].second << endl;
        };
        dfs({1, 2, 3});
    }
    else cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
