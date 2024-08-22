/*
考虑每个位置最后一次被染色的时间
对于时间相同的，其颜色应该也相同
不同时间用乘法原理乘起来即可
接下来问题就在于算一下会有多少不同的时间了
从后往前进行操作，只考虑还未被染色的行或者列
注意，假如所有的列或者所有的行被染色完了，那么前面的也都不用看了！
*/

int T;
int n, m, k, q;
int x[N], y[N];
bool colored_x[N], colored_y[N];

void solve1() {
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x[i] >> y[i];
    }
    int cnt_x = 0, cnt_y = 0;
    LL res = 1;
    for (int i = q; i > 0; i--) {
        if (colored_x[x[i]] && colored_y[y[i]]) {
            continue;
        }
        res *= k;
        res %= MOD2;
        if (!colored_x[x[i]]) {
            colored_x[x[i]] = i;
            cnt_x++;
            if (cnt_x == n) {
                break;
            }
        }
        if (!colored_y[y[i]]) {
            colored_y[y[i]] = i;
            cnt_y++;
            if (cnt_y == m) {
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        colored_x[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        colored_y[i] = 0;
    }
    cout << res << "\n";
}                                                                                                                  
