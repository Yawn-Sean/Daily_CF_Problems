/*
假设满足条件的数列有恰好 m 个，求这 m 个数列里面的最大值的最小值（记作 n）
第一个数是 a，则为 a, k * a, k^2 * a, k^3 * a
k^3 * a <= n -> a <= n / k^3
k 和 a 都可以变
m = 1e15，则 n 最大可能是多少呢？
感觉要二分答案 n，但是不清楚 n 最大能到多少，盲猜一个 4e18 吧
已知 n，计算有多少组合符合要求，是否 >= m
可以枚举 k，算 a 有多少个，k^3 <= n 所以 k 的枚举量也就 2e6 以内
对于确定的 n 和 k，a 有 n / k^3 个
*/

int T;
LL m;

bool check(LL n) {
    LL cnt = 0;
    for (LL k = 2; k * k * k <= n; k++) {
        cnt += n / k / k / k;
        if (cnt >= m) {
            return true;
        }
    }
    return cnt >= m;
}

void solve1() {
    cin >> m;
    LL l = 1, r = 4e18, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    LL cnt = 0;
    LL ans = check(l) ? l : r;
    for (LL k = 2; k * k * k <= ans; k++) {
        cnt += ans / k / k / k;
    }
    if (cnt != m) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
}      
