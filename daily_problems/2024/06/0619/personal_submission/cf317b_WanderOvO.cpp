/*
扩散出来几乎是一个菱形
面积 1->5->13->25->41...
s(n) - s(n - 1) = (n - 1) * 4
s(n - 1) - s(n - 2) = (n - 2) * 4
...
s(n) - s(1) = 4 * (1 + ... + n - 1)
s(n) = 4 * (n - 1) * n / 2 + 1
s(n) = 2 * (n - 1) * n + 1
s(n) = 2 * n^2 - 2 * n + 1
由于一共有 3e4 只蚂蚁，所以至多需要用 3e4 个位置
考虑 s(i) = 3e4，则 i 大约是 120，也就是说会往外扩展 100 多次
所以只需要维护 x, y in [-150, 150] 以内的区域，每次外扩暴力模拟
每次外扩完之后复制一份作为备份，再算新的
复杂度大约是 300 * 300 * 150
*/

int T;
int dx[5] = {0, 0, 1, -1}, dy[5] = {1, -1, 0, 0};
int cnt[N][N], last_cnt[N][N], n, q;

void solve1() {
    cin >> n >> q;
    int delta = N / 2 - 1;
    last_cnt[delta][delta] = n;
    while (true) {
        bool ok = true;
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                cnt[i][j] += last_cnt[i][j] % 4;
                if (last_cnt[i][j] >= 4) {
                    ok = false;
                    int move_cnt = last_cnt[i][j] - last_cnt[i][j] % 4;
                    for (int k = 0; k < 4; k++) {
                        cnt[i + dx[k]][j + dy[k]] += move_cnt / 4;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                last_cnt[i][j] = cnt[i][j];
            }
        }
        if (ok) {
            break;
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x += delta;
        y += delta;
        if (x <= 0 || x >= N - 1 || y <= 0 || y >= N - 1) {
            cout << "0\n";
        } else {
            cout << cnt[x][y] << "\n";
        }
    }
}         