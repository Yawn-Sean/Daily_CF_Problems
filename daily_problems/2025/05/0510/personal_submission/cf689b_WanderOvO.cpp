/*
a 单调递增
直接建图跑最短路吧还是...
*/

int n, a[N], d[N];
bool vis[N];
vector<vector<int>> e(N);

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        e[i].push_back(a[i]);
        if (i < n) {
            e[i].push_back(i + 1);
            e[i + 1].push_back(i);
        }
    }

    queue<int> q;
    memset(d, 0x3f, sizeof d);

    q.push(1);
    d[1] = 0;
    vis[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : e[u]) {
            if (!vis[v]) {
                d[v] = d[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}   
