/*
假设某一边切 x 刀，则每段的长度为 n / (x + 1)（下取整），另一边长度为 m / (k - x + 1)（下取整）
直接从 1 到 min(k, n - 1) 枚举是超时的
根据整除分块，n / (x + 1) 实际上只有 O(sqrt(n)) 个不同的取值，所以我们需要枚举的 x 是有限的
我们枚举 n 那条边被切成了 x 段，则 m 那条边被分成了 k - x + 2 段，我们要保证这两个数都是 > 0 的
对于 sqrt(n) 范围内的 x，暴力枚举
对于 > sqrt(n) 的 x，n / x 一定 < sqrt(n)
所以对于 > sqrt(n) 的部分，我们可以枚举每段的长度，然后看这个长度最多可以让 n 这边分多少块，这样 m 那边切的就尽可能少了
也可以考虑直接写整除分块来实现这一点
*/

int T;
LL n, m, k;

void solve1() {
    cin >> n >> m >> k;
    LL res = -1;
    LL mx = 2e5;
    // x 是 n 那条边最终被分成的段数
    for (LL x = 1; x <= min(mx, n); x++) {
        LL a = n / x;
        LL b = m / max(1LL, (k - (x - 1) + 1));
        if (a > 0 && b > 0) {
            res = max(res, a * b);
        }
        LL y = n / x;
        a = n / y;
        b = m / max(1LL, (k - (y - 1) + 1));
        if (a > 0 && b > 0) {
            res = max(res, a * b);
        }
    }
    cout << res << "\n";
}   
