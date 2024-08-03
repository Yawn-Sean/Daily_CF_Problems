/*
如果第 i 个条件是连接两个之前没连接的点，则直接用并查集合并这两个集合即可
如果这两个点本来就连通，则可以考虑连一个其他边
一共有 m 条边，假如每次都能把两个不在同一连通块的点合并，那么最终答案一定是 m
假如第 i 个条件的两个点本来就连通，则这类边的个数我们可以先存着
每次遇到必须加的边，就把必须加的加上，然后看当前有多少自由边，把最大的几个块灵活合并起来
数据范围很小，可以暴力算最大的几个块
*/

int T;
int fa[N], n, m, sz[N];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (!together(u, v)) {
            merge(u, v);
        } else {
            cnt++;
        }
        vector<int> vals;
        for (int j = 1; j <= n; j++) {
            if (j == find(j)) {
                vals.pb(sz[j]);
            }
        }
        sort(vals.begin(), vals.end());
        reverse(vals.begin(), vals.end());
        int ans = vals[0];
        for (int j = 1; j <= cnt; j++) {
            ans += vals[j];
        }
        cout << ans - 1 << "\n";
    }
}       