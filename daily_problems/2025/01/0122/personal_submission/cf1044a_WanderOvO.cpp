/*
只要能找到一条路，让纵坐标到 1e9 就行，横坐标不用管
枚举要删除最左边的 i 条竖着的才可以，然后看再删除几个横着的可以
一条竖线都不删除时，假设第一条竖线坐标是 y，则最开始横坐标至多只能走到 y
所以要删除多少条横线？事实上，所有没完全覆盖 [1, y] 的都不用删除，可以绕开
所以事实上只需要关心左端点是 1 的线段即可，然后按照右端点排序
题目数据保证了横着的不存在公共点，所以不用考虑两个线段连在一起的情况
*/

int n, m, idx, vertical[N], horizontal[N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> vertical[i];
    }
    vertical[n + 1] = 1e9;
    n++;
    sort(vertical + 1, vertical + n + 1);
    idx = 0;
    for (int i = 1; i <= m; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 == 1) {
            horizontal[++idx] = x2;
        }
    }
    sort(horizontal + 1, horizontal + idx + 1);
    int l = 1;
    int res = INF;
    for (int i = 1; i <= n; i++) {
        while (l <= idx && horizontal[l] < vertical[i]) {
            l++;
        }
        res = min(res, idx - l + 1 + i - 1);
    }
    cout << res << "\n";
}
