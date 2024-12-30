/*
gcd(a, b) = k, 则 gcd(a / k, b / k) = 1
找 4 个两两互素的数
显然 4 个数里面至多有一个偶数
两个相邻奇数的 gcd 是多少？
gcd(a, a + 2) = k
gcd(a / k, (a + 2) / k) = 1，且 a / k, (a + 2) / k 也必定都是奇数
则 (a + 2) / k - a / k >= 2，所以 k 只能是 1
gcd(a, a + 4) = k
gcd(a / k, (a + 2) / k) = 1，且 a / k, (a + 4) / k 也必定都是奇数
(a + 4) / k - a / k >= 2 => k = 1 或者 2，而如果 k = 2 则说明二者是偶数，矛盾
所以相邻的三个奇数一定两两互素
1 3 5 7 9 11 13 15 17 19
然后考虑第四个数选什么偶数
显然，对于 a, a + 2, a + 4(a 为奇数)来说，a + 1 或者 a + 3 就很好
这三个数对 3 的余数正好取遍了 0 1 2
如果 a 能被 3 整除，则必须选 a + 1，这个时候 a + 4 必不能被 3 整除，且 gcd(a + 1, a + 4) = 1
如果 a + 4 能被 3 整除，则必须选 a + 3，这个时候 a 必不能被 3 整除，且 gcd(a, a + 3) = 1
*/

int T;
LL n, k;

void solve1() {
    cin >> n >> k;
    LL m = (6 * n - 1) * k;
    cout << m << "\n";
    for (int i = 1; i <= n; i++) {
        LL curmax = 6 * i - 1;
        if (curmax % 3 == 0) {
            cout << (curmax - 4) * k << " " << (curmax - 2) * k << " "
                 << (curmax - 1) * k << " " << curmax * k << "\n";
        } else {
            cout << (curmax - 4) * k << " " << (curmax - 3) * k << " "
                 << (curmax - 2) * k << " " << curmax * k << "\n";
        }
    }
}     