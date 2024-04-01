
/*
  https://codeforces.com/contest/1027/submission/254055675
*/
int n, t, a[N], c[N];
int deg[N];
bool vis[N];

int dfs(int i) {
    if (!vis[i]) {
        vis[i] = true;
        int t = dfs(a[i]);
        return min(t, c[i]);
    }
    return c[i];
}

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    int to;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        deg[a[i]]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        deg[a[x]]--;
        if (deg[a[x]] == 0)
            q.push(a[x]);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] != 0 && !vis[i]) {
            res += dfs(i);
        }
    }
    cout << res << '\n';
}
