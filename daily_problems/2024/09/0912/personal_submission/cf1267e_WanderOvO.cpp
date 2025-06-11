/*
最后需要有一个人 i(i < n)，使得 i 的总票数不小于 n 的总票数
枚举一下是哪个人，然后考虑取消哪些地方的选票
假设我们枚举第 i 个人总票数 >= 第 n 个人总票数，则对于第 j 个选票站，假设 a[j][i] < a[j][n]，则可以取消
我们优先取消 a[j][n] - a[j][i] 大的选票站，贪心去取消
*/

int T;
int n, m, a[N][N];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int min_cnt = m + 1;
    vector<int> res;
    for (int i = 1; i < n; i++) {
        int opposite_cnt = 0, cur_cnt = 0;
        vector<PII> sites;
        for (int j = 1; j <= m; j++) {
            opposite_cnt += a[j][n];
            cur_cnt += a[j][i];
            sites.pb({a[j][n] - a[j][i], j});
        }
        sort(sites.begin(), sites.end());
        reverse(sites.begin(), sites.end());
        vector<int> cancel_sites;
        for (int j = 0; j < sites.size() && cur_cnt < opposite_cnt; j++) {
            int id = sites[j].y;
            cancel_sites.pb(id);
            cur_cnt -= a[id][i];
            opposite_cnt -= a[id][n];
        }
        if (cancel_sites.size() < min_cnt) {
            res = cancel_sites;
            min_cnt = res.size();
        }
    }
    cout << res.size() << "\n";
    for (auto id : res) {
        cout << id << " ";
    }
    cout << "\n";
}         
