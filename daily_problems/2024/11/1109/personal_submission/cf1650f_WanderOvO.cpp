/*
显然优先完成 ddl 比较早的任务
对于每个任务，可以单独去计算达到 100 所需要的最短消耗的时间
可以对每个任务单独算一个背包，看前 i 个训练达到 j 的的训练效果需要最短多久
做容量为 200 的背包
*/

struct Training {
    LL e, t, p, id;
};

LL n, m, a[N];
LL dp[M], from[N][M];
vector<vector<Training>> ts(N);

LL knapsack(vector<Training> &ts) {
    int cnt = ts.size();
    for (int j = 0; j < M; j++) {
        dp[j] = INFLL;
    }
    for (int i = 0; i <= cnt; i++) {
        for (int j = 0; j < M; j++) {
            from[i][j] = 0;
        }
    }
    dp[0] = 0;
    LL res = INFLL;
    for (int i = 1; i <= cnt; i++) {
        Training t = ts[i - 1];
        for (int j = M - 1; j >= t.p; j--) {
            if (dp[j] > dp[j - t.p] + t.t) {
                dp[j] = dp[j - t.p] + t.t;
                from[i][j] = 1;
            }
            if (j >= 100) {
                res = min(res, dp[j]);
            }
        }
    }
    return res;
}

void get_choose(vector<Training> &ts, vector<int> &choose) {
    int cnt = ts.size();
    for (int j = 0; j < M; j++) {
        dp[j] = INFLL;
    }
    for (int i = 0; i <= cnt; i++) {
        for (int j = 0; j < M; j++) {
            from[i][j] = 0;
        }
    }
    dp[0] = 0;
    LL res = INFLL;
    int min_capacity = 0;
    for (int i = 1; i <= cnt; i++) {
        Training t = ts[i - 1];
        for (int j = M - 1; j >= t.p; j--) {
            if (dp[j] > dp[j - t.p] + t.t) {
                dp[j] = dp[j - t.p] + t.t;
                from[i][j] = 1;
            }
            if (j >= 100) {
                if (res > dp[j]) {
                    res = dp[j];
                    min_capacity = j;
                }
            }
        }
    }
    for (int i = cnt; i > 0; i--) {
        if (from[i][min_capacity] == 1) {
            choose.push_back(ts[i - 1].id);
            min_capacity -= ts[i - 1].p;
        }
    }
    assert(min_capacity == 0);
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        ts[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        Training train;
        cin >> train.e >> train.t >> train.p;
        train.id = i;
        ts[train.e].push_back(train);
    }
    vector<LL> cost(n + 1, INFLL);
    cost[0] = 0;
    vector<int> choose;
    for (int i = 1; i <= n; i++) {
        cost[i] = knapsack(ts[i]);
        cost[i] += cost[i - 1];
        if (cost[i] > a[i]) {
            cout << "-1\n";
            return;
        }
        get_choose(ts[i], choose);
    }
    cout << choose.size() << "\n";
    for (auto choice : choose) {
        cout << choice << " ";
    }
    cout << "\n";
}
