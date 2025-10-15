/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-07 14:28 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    auto check = [&] (int x, int y, int rx, int ry, int r) -> bool {
        return 1ll * (x - rx) * (x - rx) + 1ll * (y - ry) * (y - ry) <= 1ll * r * r;
    };
    const double PI = acos(-1);
    vector rx(n, 0), ry(n, 0), r(n, 0);
    vector idx(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> rx[i] >> ry[i] >> r[i];
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&] (int x, int y) {return r[x] > r[y];});
    vector get(n, 0), st(n, 0);
    double ans = 0;
    for (int i = 0; i < n; i ++) {
        int now = idx[i];
        get[i] = 0;
        st[i] = 1;
        bool ok1 = false, ok2 = false;
        for (int j = i - 1; j >= 0; j --) {
            if (check(rx[now], ry[now], rx[idx[j]], ry[idx[j]], r[idx[j]]) && get[j] == 0) {
                if (st[j] == 1) ok1 = true;
                break;
            }
        }
        for (int j = i - 1; j >= 0; j --) {
            if (check(rx[now], ry[now], rx[idx[j]], ry[idx[j]], r[idx[j]]) && get[j] == 1) {
                if (st[j] == 1) ok2 = true;
                break;
            }
        }
        if (ok1 && ok2) st[i] = -1;
        else if (ok1 == false) st[i] = 1, get[i] = 0;
        else st[i] = 1, get[i] = 1;
        ans += 1.0 * st[i] * PI * r[now] * r[now];
        // debug("idx[i]:", idx[i], "st:", st[i]);
    }
    printf("%.10lf\n", ans);
    return 0;
}

#endif

/*

*/
