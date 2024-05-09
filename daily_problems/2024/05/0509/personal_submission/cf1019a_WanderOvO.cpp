/*
所有改票的都可以改成投 1 号，这样最优
- 让便宜的人改投自己
- 让投给票数最高的人改投自己

枚举自己赢的时候的票数 ans
让别人的票都 < ans，并且转投给自己
如果自己票已经 >= ans，则赢了
如果自己票 < ans，则继续拿最小的给自己
*/

int T;
int n, m;
vector<int> e[N];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p, c;
        cin >> p >> c;
        e[p].pb(c);
    }
    for (int i = 1; i <= m; i++) {
        sort(e[i].begin(), e[i].end());
    }
    
    LL res = 1e15;
    for (int ans = 1; ans <= n; ans++) {
        int cnt = e[1].size();
        LL cost = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 2; i <= m; i++) {
            int convert_cnt = max(0, ((int) e[i].size()) - ans + 1);
            for (int j = 0; j < convert_cnt; j++) {
                cost += e[i][j];
                cnt++;
            }
            for (int j = convert_cnt; j < e[i].size(); j++) {
                q.push(e[i][j]);
            }
        }
        if (cnt >= ans) {
            res = min(res, cost);
        } else {
            while (cnt < ans) {
                cnt++;
                cost += q.top();
                q.pop();
            }
            res = min(res, cost);
        }
    }
    cout << res << "\n";
}           