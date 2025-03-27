/*
枚举 x, y，建立 0-9 的图，跑 floyd 计算 x, y 的情况下从 i 转化到 j 的最小操作次数
枚举 x, y，计算凑够和为 s 至少需要多少次变化，其中 s <= 100
枚举 s[i] 和 s[i + 1]，看从 s[i] 变到 s[i + 1] + 10^j 至少需要多少次，假设为 cnt 次，则需要插入 cnt - 1 个数
*/

string s;
int dist[110], mod_dist[110], n;
LL ans[M][M];

void calc(int x, int y) {
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    for (int i = 1; i < 110; i++) {
        if (i >= x) {
            dist[i] = min(dist[i], dist[i - x] + 1);
        }
        if (i >= y) {
            dist[i] = min(dist[i], dist[i - y] + 1);
        }
    }
}

void meibao() {
    cin >> s;
    n = s.size();
    for (int x = 0; x < M; x++) {
        for (int y = x; y < M; y++) {
            calc(x, y);
            LL res = 0;
            memset(mod_dist, 0x3f, sizeof mod_dist);
            for (int i = 1; i < 110; i++) {
                mod_dist[i % 10] = min(mod_dist[i % 10], dist[i]);
            }
            for (int i = 0; i + 1 < n; i++) {
                int d = s[i + 1] - s[i];
                // s[i] = s[i + 1] 说明中间缺一堆数，不是不缺数
                // 但如果 x 和 y 中有一个为 0，则 s[i] = s[i + 1] 其实中间真的不缺数，要特判一下
                int cnt = INF;
                if (s[i] == s[i + 1] && (x == 0 || y == 0)) {
                    cnt = 1;
                }
                while (d < 0) {
                    d += 10;
                }
                cnt = min(cnt, mod_dist[d]);
                if (cnt == INF) {
                    res = -1;
                    break;
                } else {
                    res += cnt - 1;
                }
            }
            ans[x][y] = res;
            ans[y][x] = res;
        }
    }
    for (int x = 0; x < M; x++) {
        for (int y = 0; y < M; y++) {
            cout << ans[x][y] << " ";
        }
        cout << "\n";
    }
}   
