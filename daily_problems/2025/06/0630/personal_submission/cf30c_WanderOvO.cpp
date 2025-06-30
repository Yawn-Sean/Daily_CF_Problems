/*
按照时间排序所有目标
dp[i]: 只考虑打前 i 个目标，且第 i 个目标必打，至多打多少个
dp[i] = dp[j] + p[i]，如果 dist(j, i) <= t[i] - t[j]
*/
 
struct Target {
    int x, y;
    LL t;
    double p;
 
    bool operator<(const Target &o) const {
        return t < o.t;
    }
};
 
double dp[N];
int n;
Target targets[N];
 
void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> targets[i].x >> targets[i].y >> targets[i].t >> targets[i].p;
    }
    sort(targets + 1, targets + n + 1);
 
    auto dist = [&] (int i, int j) -> int {
        int d1 = targets[i].x - targets[j].x;
        int d2 = targets[i].y - targets[j].y;
        return d1 * d1 + d2 * d2;
    };
 
    double res = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = targets[i].p;
        for (int j = i - 1; j > 0; j--) {
            if (dist(i, j) <= (targets[i].t - targets[j].t) * (targets[i].t - targets[j].t)) {
                dp[i] = max(dp[i], dp[j] + targets[i].p);
            }
        }
        res = max(res, dp[i]);
    }
    cout << setprecision(15) << res << "\n";
}
