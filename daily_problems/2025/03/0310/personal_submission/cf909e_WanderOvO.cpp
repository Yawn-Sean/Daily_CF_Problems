/*
先贪心把当前主处理器能做的任务都处理了，这个时候所有入度为 0 的任务一定都是只能由协处理器做的任务
然后把当前协处理器能做的任务都处理了
*/

int n, m, type[N];
vector<vector<int>> e(N);
int d[N], vis[N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> type[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u++;
        v++;
        e[v].push_back(u);
        d[u]++;
    }

    int res = 0;
    queue<int> q[2];
    int finished = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            q[type[i]].push(i);
        }
    }
    for (int rd = 0; finished < n; rd++) {
        int cur = rd % 2;
        if (cur == 1) {
            res++;
        }
        while (!q[cur].empty()) {
            int u = q[cur].front();
            q[cur].pop();
            finished++;
            for (auto v : e[u]) {
                d[v]--;
                if (d[v] == 0) {
                    q[type[v]].push(v);
                }
            }
        }
    }
    cout << res << "\n";
}
