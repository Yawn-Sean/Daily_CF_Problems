/*
原本的距离是 d(u, v)，现在变成 (d(u, v) + 1) / 2
考虑怎么求这个和
假如原本 d(u, v) 是偶数，则好说
假如原本 d(u, v) 是奇数，则需要上取整
对于 d(u, v) 的求和，只需要算一下两边点的个数，就知道每条边贡献了多少次
把贡献都加起来，就是 d(u, v) 的和
下面考虑怎么把上取整加进去，其实就是看有多少为奇数的情况
把树当成二分图，染色，则两种颜色的个数相乘就是奇数的情况数
*/

int T;
vector<vector<int>> e(N);
LL color[N], n, sz[N];

void dfs(int u, int fa, int c) {
    color[u] = c;
    sz[u] = 1;
    for (auto &v : e[u]) {
        if (v != fa) {
            dfs(v, u, c ^ 1);
            sz[u] += sz[v];
        }
    }
}

void solve1() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1, 0, 0);
    LL res = 0;
    LL cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i]) {
            cnt++;
        }
    }
    res = cnt * (n - cnt);
    for (int i = 1; i <= n; i++) {
        res += sz[i] * (n - sz[i]);
    }
    cout << res / 2 << "\n";
}  