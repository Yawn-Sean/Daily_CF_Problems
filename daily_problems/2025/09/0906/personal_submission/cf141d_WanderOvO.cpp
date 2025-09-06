/*
题意：
最开始在 0，想走到 L，正常走的速度是 1m/s
中间有 n 个点，每个点有机会起飞，第 i 个点在 x[i] 位置，从第 i 个点起飞可以在 t[i] 秒内飞行 d[i] 米
但是为了在 i 点起飞，它需要在起飞前先助跑 p[i] 米
具体来说，假如想要从 x[i] 起飞，我们至少需要在 x[i] - p[i] 处助跑，在 x[i] 处起跳，经过 t[i] 秒飞到了 x[i] + d[i]
我们没有必要在每个点都起跳，我们也可以往反方向走以获得足够的助跑距离（不能走到小于 0 的位置）
求从 0 到 L 的最短时间，需要在几个点起跳，并输出到底在哪几个点起跳的

思路：
考虑 dp，dp[i][0/1] 走到第 i 个点时不起跳/起跳的最短时间
起跳可能会导致飞过去错过某些起跳点
dp[i][0]:
- 上一个点不起跳，dp[i - 1][0] + x[i] - x[i - 1]，无条件
- 上一个点起跳，dp[i - 1][1] + t[i - 1] + x[i] - (x[i - 1] + d[i - 1])
  需要 x[i] >= x[i - 1] + d[i - 1]
  倘若 x[i] < x[i - 1] + d[i - 1]，说明跳过了，需要往回走
  所以代价是 dp[i - 1][1] + t[i - 1] + (x[i - 1] + d[i - 1] - x[i])
  总的来说就是 dp[i - 1][1] + t[i - 1] + abs(x[i] - (x[i - 1] + d[i - 1]))
dp[i][1]:
- 上一个点不起跳
  如果 x[i] - x[i - 1] >= p[i]，则 dp[i - 1][0] + x[i] - x[i - 1]
  如果 x[i] - x[i - 1] < p[i]，则 dp[i - 1][0] + (p[i] - x[i] + x[i - 1]) + p[i]，这里需要 x[i] - p[i] >= 0
- 上一个点起跳
  如果 x[i] - (x[i - 1] + d[i - 1]) >= p[i]，则 dp[i - 1][1] + t[i - 1] + x[i] - (x[i - 1] + d[i - 1])
  如果 x[i] - (x[i - 1] + d[i - 1]) < p[i]，则需要往回走
  dp[i - 1][1] + t[i - 1] + (x[i - 1] + d[i - 1]) - (x[i] - p[i]) + p[i]，需要 x[i] - p[i] >= 0
最终答案，dp[n][0] + L - x[n] 或者 dp[n][1] + t[n] + L - (x[n] + d[n])
每个点是否至多起跳一次？
有没有可能某个位置有多个起跳点？所以不一定是从 i - 1 开始起跳
由于可能越过起跳点，所以事实上我们枚举的不是 i - 1，而是“上一个经过的点”
这样转移就很复杂了

还是硬求最短路吧，考虑连边，先是 x[i - 1] 到 x[i] 连接时间为 x[i] - x[i - 1] 的边
另外，我们还关心 x[i] - p[i] 和 x[i] + d[i]，这两个点之间需要连长度为 p[i] + t[i] 的边
这样的话，上面的就需要做一些修改，我们把所有涉及到的点按照坐标排个序
然后相邻点之间连双向边，最后 x[i] - p[i] 和 x[i] + d[i] 之间连 p[i] + t[i] 的边
需要离散化一下
*/

struct Point {
    LL x, d, t, p;
};

struct Edge {
    LL v, w;
    int leap_id;
};

LL n, L;
Point a[N];
vector<vector<Edge>> e(N);
LL d[N], vis[N], from[N];
int is_leap[N];
vector<int> all_positions;

void dijkstra(int st) {
    memset(vis, 0, sizeof vis);
    memset(d, 0x3f, sizeof d);
    d[st] = 0;
    priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();

        LL u = tp.y;
        if (vis[u]) continue;

        vis[u] = true;
        for (auto edge : e[u]) {
            LL v = edge.v, w = edge.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                from[v] = u;
                pq.push({d[v], v});
                is_leap[v] = edge.leap_id;
            }
        }
    }
}

void meibao() {
    cin >> n >> L;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].d >> a[i].t >> a[i].p;
    }

    all_positions.push_back(0);
    all_positions.push_back(L);
    map<PII, int> leap;
    for (int i = 1; i <= n; i++) {
        all_positions.push_back(a[i].x);
        if (a[i].x >= a[i].p) {
            all_positions.push_back(a[i].x - a[i].p);
            leap[{a[i].x - a[i].p, a[i].x + a[i].d}] = i;
        }
        all_positions.push_back(a[i].x + a[i].d);
    }

    sort(all_positions.begin(), all_positions.end());
    all_positions.erase(unique(all_positions.begin(), all_positions.end()), all_positions.end());

    int m = all_positions.size();
    for (int i = 0; i + 1 < m; i++) {
        e[i].push_back({i + 1, all_positions[i + 1] - all_positions[i], 0});
        e[i + 1].push_back({i, all_positions[i + 1] - all_positions[i], 0});
    }

    for (int i = 1; i <= n; i++) {
        if (a[i].x >= a[i].p) {
            int p1 = a[i].x - a[i].p, p2 = a[i].x + a[i].d;
            p1 = lower_bound(all_positions.begin(), all_positions.end(), p1) - all_positions.begin();
            p2 = lower_bound(all_positions.begin(), all_positions.end(), p2) - all_positions.begin();
            e[p1].push_back({p2, a[i].p + a[i].t, i});
        }
    }

    dijkstra(0);

    cout << d[m - 1] << "\n";
    int cur = m - 1;
    vector<int> res;
    while (cur > 0) {
        int last = from[cur];
        if (is_leap[cur]) {
            res.push_back(is_leap[cur]);
        }
        cur = last;
    }

    reverse(res.begin(), res.end());
    cout << res.size() << "\n";
    for (auto id : res) {
        cout << id << " ";
    }
}
