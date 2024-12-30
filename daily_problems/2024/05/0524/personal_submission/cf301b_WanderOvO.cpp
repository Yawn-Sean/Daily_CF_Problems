/*
根据数据范围，途中至多获得 1e5 的补给
坐标差最多是 400
关键观察：没有重合点，a[i] <= 1000 <= d
所以不管怎么走都会越来越少 (a[i] - d * dist(u, v) <= 0 恒成立)
我们考虑 (u, v) 的边权为 d * dist(u, v) - a[i]，则问题变成了求 1 到 n 的最短路
*/

int T;
LL n, c, a[N], d[N];
bool st[N];
LL x[N], y[N];

void solve1() {
    cin >> n >> c;
    for (int i = 2; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    dijkstra(1);

    cout << d[n] << endl;
}       