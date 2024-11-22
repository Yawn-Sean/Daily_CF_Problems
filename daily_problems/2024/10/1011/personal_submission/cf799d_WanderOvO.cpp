/*
假如用了 cnt 个操作可以，那么强制用最大的那 cnt 个一定也可以
注意到可以旋转，所以要算两种情况
可以算出 h 和 w 各至少需要变成原来的多少倍才能符合题意，假设是 cnt1 倍和 cnt2 倍
注意到 a[i] 至少是 2，a, b, h, w <= 1e5，所以至多用 17 个操作就可以把一条边的长度弄够
所以只需要考虑最大的 34 个操作就行，其他的不会用到
*/

int n, a, b, h, w, times[N];

int calc2(int a, int b, int h, int w) {
    map<PII, int> cnt;
    int cnt1 = (a + h - 1) / h, cnt2 = (b + w - 1) / w;
    cnt[{cnt1, cnt2}] = 0;
    for (int i = 1; i <= n; i++) {
        vector<PII> cur_states;
        for (auto &it : cnt) {
            cur_states.pb(it.x);
        }
        for (auto &state : cur_states) {
            int c = cnt[state];
            int x = state.x, y = state.y;
            int new_x = (x + times[i] - 1) / times[i], new_y = y;
            if (!cnt.count({new_x, new_y})) {
                cnt[{new_x, new_y}] = c + 1;
            }
            new_x = x, new_y = (y + times[i] - 1) / times[i];
            if (!cnt.count({new_x, new_y})) {
                cnt[{new_x, new_y}] = c + 1;
            }
        }    
    }
    int res = INF;
    if (cnt.count({1, 1})) {
        res = cnt[{1, 1}];
    }
    return res;
}

void meibao() {
    cin >> a >> b >> h >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> times[i];
    }
    sort(times + 1, times + n + 1);
    reverse(times + 1, times + n + 1);
    n = min(n, 34);
    int res1 = calc2(a, b, h, w);
    int res2 = calc2(a, b, w, h);
    int res = min(res1, res2);
    if (res == INF) {
        res = -1;
    }
    cout << res << "\n";
} 
