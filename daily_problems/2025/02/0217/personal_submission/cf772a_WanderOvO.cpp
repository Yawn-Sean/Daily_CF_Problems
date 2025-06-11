/*
假设至多用 cnt 秒才会使得某个用到 0，则每个都应该至少有 cnt * a[i] 的电量，这个事情可以二分答案
如果充电能力 p >= 所有设备的单位耗电量之和，则可以无限使用
注意时间可以是浮点数
对于那些电量不够的，我们可以算出每个需要充多少秒，但是我们采用什么样的调度策略去充电呢？
调度似乎无需担心，假如我们能最终结果在 cnt 秒这个状态时有设备的电量变成 0，就会存在对应的调度方案
使用 kahan 求和
*/
 
LL n, p, a[N], b[N];
 
bool check(double cnt) {
    double tot_need = 0;
    double c = 0;
    for (int i = 1; i <= n; i++) {
        double need = max(0.0, a[i] * cnt - b[i]) - c;
        double t = tot_need + need;
        c = (t - tot_need) - need;
        tot_need = t;
    }   
    return (cnt * p > tot_need || (fabs(cnt * p - tot_need) < eps));
}
 
void meibao() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
 
    double l = 0, r = 1e12, mid;
    for (int rd = 0; rd < 100; rd++) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
 
    if (l > 1e11) {
        cout << "-1\n";
    } else {
        cout << setprecision(15) << l << "\n";
    }
}
