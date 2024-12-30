/*
对于两个圆 (x[i], y[i], r[i]), (x[j], y[j], r[j])
如果原本有 dist(i, j) == r[i] + r[j]，则后面也应该满足
如果 i, j 相切，i, k 相切，j, k 不相切，则可以考虑扩大 i 的半径，缩小 j, k 的半径
假如 (i, j) 相切，则考虑连一条 (i, j) 无向边
delta = min(dist(i, j) - r[i] - r[j]) / 2（非相切的）
只要有一个分支是二分图，且两个部的结点数量不一样即可
*/

int T;
vector<int> e[N];
LL x[N], y[N], r[N];
int n, color[N], cnt[2];
bool ok = true;

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            LL dx = x[i] - x[j];
            LL dy = y[i] - y[j];
            if (dx * dx + dy * dy == (r[i] + r[j]) * (r[i] + r[j])) {
                e[i].pb(j);
                e[j].pb(i);
            }
        }
    }
    memset(color, -1, sizeof color);
    for (int i = 1; i <= n; i++) {
        if (color[i] < 0) {
            cnt[0] = 0;
            cnt[1] = 0;
            ok = true;
            dfs(i, 0);
            if (ok && cnt[0] != cnt[1]) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}   