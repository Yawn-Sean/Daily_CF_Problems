/*
显然可以二分答案，但关键在于咋算面积，算面积的关键又在于算出被边界挡住了多少
无边界限制，扩散 t 的时间，面积为 2 * t * t + 2 * t + 1
考虑突破了某个边界 cnt 格，则需要减掉 cnt * cnt 个格子
但是同时突破两个相邻的边界，可能会重复减去角的部分突破的面积
*/

void meibao() {
    LL n, x, y, c;
    cin >> n >> x >> y >> c;
    LL l = 0, r = 1e9, mid;

    auto check = [&] (LL ans) -> bool {
        LL sum = 2 * ans * ans + 2 * ans + 1;
        LL up = x - ans, down = x + ans, left = y - ans, right = y + ans;

        if (up <= 0) {
            LL cnt = -up + 1;
            sum -= cnt * cnt;
        }

        if (down > n) {
            LL cnt = down - n;
            sum -= cnt * cnt;
        }

        if (left <= 0) {
            LL cnt = -left + 1;
            sum -= cnt * cnt;
        }

        if (right > n) {
            LL cnt = right - n;
            sum -= cnt * cnt;
        }

        if (ans > (x - 1) + (y - 1)) {
            LL cnt = ans - (x - 1 + y - 1);
            sum += cnt * (cnt - 1) / 2;
        }

        if (ans > (x - 1) + (n - y)) {
            LL cnt = ans - (x - 1 + n - y);
            sum += cnt * (cnt - 1) / 2;
        }

        if (ans > (n - x) + (y - 1)) {
            LL cnt = ans - (n - x + y - 1);
            sum += cnt * (cnt - 1) / 2;
        }

        if (ans > (n - x) + (n - y)) {
            LL cnt = ans - (n - x + n - y);
            sum += cnt * (cnt - 1) / 2;
        }
        return sum >= c;
    };

    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) {
        cout << l << "\n";
    } else {
        cout << r << "\n";
    }
}
