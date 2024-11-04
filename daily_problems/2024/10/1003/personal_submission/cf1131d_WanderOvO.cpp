/*
id 设为 1-n 和 n + 1-n + m
不妨先把所有相等的用并查集给 merge 起来
a[i] < b[j]，则连接 find(i) 到 find(n + j) 的一条有向边，反之就连接反向边
整个图再建出来就不应该有环了，有环就直接寄掉
对整个图跑一遍拓扑排序 + DP 即可
*/

int n, m;
string s[N];
int fa[N];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    for (int i = 1; i <= n + m; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '=') {
                merge(i, n + j);
            }
        }
    }

    vector<vector<int>> e(n + m + 1);
    vector<int> deg(n + m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int fi = find(i), fj = find(n + j);
            if (s[i][j] == '>') {
                e[fj].pb(fi);
                deg[fi]++;
            } else if (s[i][j] == '<') {
                e[fi].pb(fj);
                deg[fj]++;
            }
        }
    }
    vector<int> dp(n + m + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n + m; i++) {
        int f = find(i);
        if (f == i && deg[f] == 0) {
            q.push(f);
            dp[f] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : e[u]) {
            deg[v]--;
            dp[v] = max(dp[v], dp[u] + 1);
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n + m; i++) {
        if (deg[i] != 0) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << dp[find(i)] << " ";
    }
    cout << "\n";
    for (int i = n + 1; i <= n + m; i++) {
        cout << dp[find(i)] << " ";
    }
    cout << "\n";
}             
