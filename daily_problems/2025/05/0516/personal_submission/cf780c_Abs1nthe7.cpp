#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//本题的思路应该是
//对于每个树，他染的颜色贡献最大应该是g[i].size()+1//整颗子树的大小，具体贡献取决与他的长辈
//对于子树的染色，只需要继续染不同与长辈的就行
void sol() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 计算最大度数
    int _max = 0;
    for (int i = 1; i <= n; ++i) {
        _max = max(_max, (int)g[i].size()+1);
    }
    int k = max(3LL, _max); // 颜色数至少为3

    // BFS染色，避免父节点和祖父节点的颜色
    vector<int> color(n + 1, 0);
    vector<int> fa(n + 1, -1);
    queue<int> q;
    q.push(1);
    color[1] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int c = 1; // 当前尝试的颜色
        for (int v : g[u]) {
            if (v == fa[u]) continue;

            // 避开父节点和祖父节点的颜色
            while (c == color[u] || (fa[u] != -1 && c == color[fa[u]])) {
                c++;
            }
            color[v] = c++;
            fa[v] = u;
            q.push(v);
        }
    }
    cout << k << endl;
    for (int i = 1; i <= n; ++i) {
        cout << color[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--) sol();
    return 0;
}
