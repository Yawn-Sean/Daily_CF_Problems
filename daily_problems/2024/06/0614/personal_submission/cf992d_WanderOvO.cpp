/*
区间和最大是 2e13，每个数 >= 1，k 最大是 1e5
所以区间里面 >= 2 的数不超过 70 个
1 对乘积没有贡献
每个下标 i 右边第一个不为 1 的数的位置记为 pos[i]，没有则为 n + 1
考虑枚举数组左端点 l，r = l, r = pos[r] 往后跳
如果 k * (s[pos[r] - 1] - s[l - 1]) >= prod(l...p)
且 k * (s[r] - s[l - 1]) <= prod(l...p)
还得保证整除
则说明 [r, pos[r] - 1] 中存在 p，使得 k * (s[p] - s[l - 1]) == prod(l...p)
一旦跳到区间乘积 >= 2e18，则无需再跳了，这里可能要用除法判断
*/

int T;
LL n, k, a[N], s[N], pos[N];

void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    LL max_prod = 2e18;
    pos[n] = n + 1;
    for (int i = n - 1; i > 0; i--) {
        pos[i] = (a[i + 1] != 1 ? (i + 1) : pos[i + 1]);
    }
    LL res = 0;
    for (int l = 1; l <= n; l++) {
        int r = l;
        LL prod = a[l];
        while (r <= n) {
            int nr = pos[r];
            if (k * (s[nr - 1] - s[l - 1]) >= prod
                && k * (s[r] - s[l - 1]) <= prod && prod % k == 0) {
                res++;
            }
            if (nr != n + 1) {
                if (prod <= max_prod / a[nr]) {
                    prod *= a[nr];
                } else {
                    break;
                }
            }
            r = nr;
        }
    }
    cout << res << "\n";
}            