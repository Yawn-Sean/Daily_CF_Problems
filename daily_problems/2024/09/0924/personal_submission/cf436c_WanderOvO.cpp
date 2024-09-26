/*
先预处理两两之间的差距
假设目前要传 i level，要么花费 n * m，要么找前面差距最小的 * w
d * w <= n * m 时使用第二个办法才更好
倘若一个包和其他包的差距总是太大，则这些包可以不管顺序先处理掉
对于剩下的，有点像 prim 最小生成树？
设立虚拟源点 0，每个点和 0 连接代价为 n * m 的边，然后点与点之间再连接差距 * w 的边
最开始只把 0 加进去，然后求 MST 即可
*/

struct Level {
    string s[12];
};

int n, m, k, w;
int d[M][M];
Level levels[M];

int calc(int id1, int id2) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (levels[id1].s[i][j] != levels[id2].s[i][j]) {
                res++;
            }
        }
    }
    return res * w;
}

void prim() {
    bool vis[M] = {false};
    int res = 0;
    vector<PII> plans;
    int dist[M], pre[M];
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i <= k; i++) {
        pre[i] = 0;
    }
    dist[0] = 0;
    for (int rd = 0; rd <= k; rd++) {
        int min_len = INF, min_pos = -1;
        for (int i = 0; i <= k; i++) {
            if (!vis[i]) {
                if (dist[i] < min_len) {
                    min_len = dist[i];
                    min_pos = i;
                }
            }
        }
        assert(min_pos != -1);
        vis[min_pos] = true;
        if (min_pos != 0) {
            res += min_len;
            plans.pb({min_pos, pre[min_pos]});
        }
        for (int i = 0; i <= k; i++) {
            if (!vis[i] && dist[i] > d[min_pos][i]) {
                dist[i] = d[min_pos][i];
                pre[i] = min_pos;
            }
        }
    }
    cout << res << "\n";
    for (auto plan : plans) {
        cout << plan.x << " " << plan.y << "\n";
    }
}

void solve1() {
    cin >> n >> m >> k >> w;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> levels[i].s[j];
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            d[i][j] = calc(i, j);
        }
    }
    for (int i = 1; i <= k; i++) {
        d[0][i] = n * m;
        d[i][0] = n * m;
    }
    prim();
}        
