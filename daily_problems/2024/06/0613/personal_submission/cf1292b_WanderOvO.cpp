/*
画图可知，由于 ax, ay >= 2, bx, by >= 0，所以一定是一条 y = x 上方的直线
x 和 y 坐标增长很快，假设 ax = 2, bx = 0, 则 x(i) = 2 * x(i - 1)，指数增长
在题给 t 限制下，至多也就能拿到几十个数据点
我们直接算出来这几十个数据点的位置，然后其实就是考虑第一个数据点取谁，以及取完之后往哪边走
似乎不需要考虑折返的情况，因为可以被其他的直接走的情况包含
看起来一定会连续的取，因为总是顺路的
由于数据点个数极小，所以只需暴力做即可
*/

int T;
LL x[N], y[N], ax, ay, bx, by, xs, ys, t;

void solve1() {
    cin >> x[0] >> y[0] >> ax >> ay >> bx >> by >> xs >> ys >> t;
    int n = 0;
    LL mx = 1e16 + 10;
    for (int i = 1; x[i - 1] <= mx && y[i - 1] <= mx; i++) {
        x[i] = x[i - 1] * ax + bx;
        y[i] = y[i - 1] * ay + by;
        n++;
    }
    int res = 0;
    for (int st = 0; st <= n; st++) {
        LL left_t = t;
        LL cost = abs(xs - x[st]) + abs(ys - y[st]);
        if (cost <= left_t) {
            left_t -= cost;
            int ans = 1, cnt1 = 0, cnt2 = 0;
            for (int j = st - 1; j >= 0; j--) {
                cost = abs(x[j] - x[j + 1]) + abs(y[j] - y[j + 1]);
                if (cost <= left_t) {
                    left_t -= cost;
                    cnt1++;
                } else {
                    break;
                }
            }
            for (int j = st + 1; j <= n; j++) {
                cost = abs(x[j] - x[j - 1]) + abs(y[j] - y[j - 1]);
                if (cost <= left_t) {
                    left_t -= cost;
                    cnt2++;
                } else {
                    break;
                }
            }
            ans = max(cnt1, cnt2) + ans;
            res = max(res, ans);
        }
    }
    cout << res << "\n";
}         