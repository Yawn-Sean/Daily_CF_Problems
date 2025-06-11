/*
考虑第 i 个人最终得多少分，且先默认都能组队，等最后再枚举不能组队的，把贡献减掉即可
考虑 i 和 j 组队，取的其实就是 min(x[i] + y[j], x[j] + y[i])
x[i] + y[j] < x[j] + y[i] => x[i] - y[i] < x[j] - y[j]
只要满足这个条件的 j，就是贡献 x[i] + y[j]，否则就是贡献 x[j] + y[i]
所有人按照 x[i] - y[i] 排序，则左边的求 x[i] 的和，右边的求 y[i] 的和
最后枚举不能组队的，把贡献减掉即可
*/

struct Person {
    LL id, x, y;
};

PLL e[N], origin_ps[N];
Person ps[N];
LL res[N], sx[N], sy[N];
int n, m;

bool cmp(const Person &o1, const Person &o2) {
    return (o1.x - o1.y) < (o2.x - o2.y);
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> origin_ps[i].x >> origin_ps[i].y;
        ps[i].x = origin_ps[i].x;
        ps[i].y = origin_ps[i].y;
        ps[i].id = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> e[i].x >> e[i].y;
    }
    sort(ps + 1, ps + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        sx[i] = sx[i - 1] + ps[i].x;
        sy[i] = sy[i - 1] + ps[i].y;
    }
    for (int i = 1; i <= n; i++) {
        int id = ps[i].id;
        res[id] += sx[i - 1] + sy[n] - sy[i] + (n - i) * ps[i].x + (i - 1) * ps[i].y;
    }
    for (int i = 1; i <= m; i++) {
        int u = e[i].x, v = e[i].y;
        res[u] -= min(origin_ps[u].x + origin_ps[v].y, origin_ps[u].y + origin_ps[v].x);
        res[v] -= min(origin_ps[u].x + origin_ps[v].y, origin_ps[u].y + origin_ps[v].x);
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}     
