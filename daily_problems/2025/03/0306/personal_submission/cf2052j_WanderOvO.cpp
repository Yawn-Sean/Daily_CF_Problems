/*
把所有作业按照 ddl 排序
ddl 在 tk 之前的，在 tk 这个时刻时这些作业一定是做完的状态，所以不妨上来就做完它们
做完它们之后，一直到 tk 的时间就只追剧，按照顺序追，追到最后一个 tk 之前能追完的剧，然后继续做作业
这样并不一定可行，因为可能导致后边的作业来不及做了
还要预处理为做完某个后缀的作业，最晚应该啥时候开始做
假设给定 tk，前 i 个作业在 <= tk 时就做完了，就先做了这些
假如做完这些之后时间变成了 cur
看预处理的要做完 i + 1 到 n 的作业，最晚应该 latest[i + 1] 时开始
则从 [cur, min(latest[i + 1], tk)] 都可以追剧，这个时间长度在剧的前缀和上二分即可
如何求 latest[i]？考虑从后往前求
latest[n] = ts[n].d - ts[n].a
latest[i] = min(ts[i].d, latest[i + 1]) - ts[i].a
如果 latest[i] < 0，说明这些任务不可能规定时间内做完
*/

struct Task {
    LL a, d;

    bool operator<(const Task &o) const {
        if (d == o.d) {
            return a < o.a;
        }
        return d < o.d;
    }
};

struct Query {
    LL id, t;

    bool operator<(const Query &o) const {
        return t < o.t;
    }
};

LL n, m, q;
LL l[N], latest[N], sum_cost[N];
Task ts[N];
Query qs[N];

void meibao() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ts[i].a;
    }
    for (int i = 1; i <= n; i++) {
        cin >> ts[i].d;
    }
    for (int i = 1; i <= m; i++) {
        cin >> l[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> qs[i].t;
        qs[i].id = i;
    }

    sort(ts + 1, ts + n + 1);

    latest[n + 1] = INFLL;
    latest[n] = ts[n].d - ts[n].a;
    for (int i = n - 1; i > 0; i--) {
        latest[i] = min(ts[i].d, latest[i + 1]) - ts[i].a;
    }

    for (int i = 2; i <= m; i++) {
        l[i] += l[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        sum_cost[i] = sum_cost[i - 1] + ts[i].a;
    }

    for (int i = 1; i <= q; i++) {
        LL t = qs[i].t;
        Task target;
        target.d = t;
        target.a = INF;
        int must_finish_cnt = upper_bound(ts + 1, ts + n + 1, target) - ts;
        must_finish_cnt--;
        LL cur = sum_cost[must_finish_cnt];
        LL latest_start = min(latest[must_finish_cnt + 1], t);
        LL len = latest_start - cur;
        cout << upper_bound(l + 1, l + m + 1, len) - l - 1 << " ";
    }
    cout << "\n";
}
