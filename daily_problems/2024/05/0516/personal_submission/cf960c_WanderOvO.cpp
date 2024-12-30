/*
一共有 2^n - 1 个非空子序列，删除掉所有的 max - min >= d 的子序列后还剩 x 个
1 2 3 4 5 6 7 8
双指针扫描，卡 a[r] - a[l] 恰好 < d，则有 2^(r - l + 1) - 1 种非空的取法
为了方便，我们不妨人为把数列构造成一段一段的，其中段内差 < d，段间差 >= d
为了保证段内差不受长度影响，可以段内都相等
*/

int T;
LL n, d, a[N], idx, val = 1;

LL qpow(LL a, LL b) {
    LL res = 1, base = a;
    while (b) {
        if (b & 1) {
            res *= base;
        }
        base *= base;
        b >>= 1;
    }
    return res;
}

void solve1() {
    cin >> n >> d;
    while (n > 0) {
        LL len = 1;
        while (true) {
            LL cnt = qpow(2, len) - 1;
            if (cnt == n) {
                break;
            } else if (cnt < n) {
                if (qpow(2, len + 1) - 1 <= n) {
                    len++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        n -= (qpow(2, len) - 1);
        for (int i = 1; i <= len; i++) {
            a[++idx] = val;
        }
        val += d + 1;
    }
    cout << idx << "\n";
    for (int i = 1; i <= idx; i++) {
        cout << a[i] << " ";
    }
}     