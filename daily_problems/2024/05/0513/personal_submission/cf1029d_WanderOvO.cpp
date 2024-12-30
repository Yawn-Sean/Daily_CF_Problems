/*
不妨枚举右边的那个，假设是 cnt 位数，则其他数相当于乘了 10^cnt
能否把每个数 * 10^cnt (0 <= cnt <= 10) 再 % k 的余数都求出来
然后维护 10 个 map，看每个里面余数的个数
*/

int T;
LL n, k, a[N], c[N];
int mod[N][11];
unordered_map<int, int> cnt[11];

void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[0][a[i] % k]++;
        mod[i][0] = a[i] % k;
        LL b = a[i] % k;
        for (int j = 1; j <= 10; j++) {
            b *= 10;
            b %= k;
            cnt[j][b]++;
            mod[i][j] = b;
        }
        int cc = 0;
        int val = a[i];
        while (val > 0) {
            cc++;
            val /= 10;
        }
        c[i] = cc;
    }

    LL res = 0;
    for (int i = 1; i <= n; i++) {
        int cc = c[i];
        int m = a[i] % k;
        int rm = (k - m) % k;
        // cout << a[i] << " " << rm << "\n";
        if (cnt[cc].count(rm)) {
            res += cnt[cc][rm];
            if (rm == mod[i][cc]) {
                res--;
            }
        }
    }
    cout << res << endl;
}                                                                                                                  