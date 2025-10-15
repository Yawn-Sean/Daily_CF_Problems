/*
是否一定有解？取 k = 1，一定是对的
假设一个环的长度为 len，则环上的颜色种类数一定得是 len 的约数
把这些约数放一个集合里，一直做交集，最后剩下最大的就是答案
倘若是 DAG，那 k = n 都没关系
如何判断图中有没有大小是 len 的环？
是不是可以先求一下最小的环呢？求其约数，然后再针对性地看，但是求最小环复杂度很高

羊神提示：固定一个点的颜色，则其他点的颜色如何呢？
假设重复走到了某个点，则这个点现在有两个颜色了，这两个颜色应该满足什么条件呢？应该差值是 k 的倍数
为什么呢？考虑每条边把反向边也建上，反向边意味着 -1，则上面那个事情就很显然了
两种方式走到同一个点，在有反向边的图上就说明找到了一个环
所以，每走到一个已经走过的点，就把差值贡献到 gcd 里
*/

int n, m;
vector<vector<PII>> e(N);
int color[N];
int res = 0;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void dfs(int u) {
    for (auto &edge : e[u]) {
        int v = edge.x, w = edge.y;
        if (color[v] == INF) {
            color[v] = color[u] + w;
            dfs(v);
        } else {
            int d = color[u] + w - color[v];
            d = abs(d);
            res = gcd(res, d);
        }
    }
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back({b, 1});
        e[b].push_back({a, -1});
    }

    memset(color, 0x3f, sizeof color);

    for (int i = 1; i <= n; i++) {
        if (color[i] == INF) {
            color[i] = 0;
            dfs(i);
        }
    }

    if (res == 0) {
        res = n;
    }
    cout << res << "\n";
}
