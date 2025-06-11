/*
从 (n, x) 开始做，其中 x < n，最后反着做回 (1, 1)
如何计算 (a, b) 到 (1, 1) 的最少操作次数？
不妨 a > b，首先 a -= b，直到 a < b，相当于操作 a / b 次，变成 a % b
然后继续做，最终做到 (1, 1)，能做到 (1, 1)，说明 n 和 x 互素
*/

int n;
int cnt = 0;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void calc(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (b == 0) {
        assert(a == 1);
        cnt--;
        return;
    }
    cnt += a / b;
    calc(b, a % b);
}

void meibao() {
    cin >> n;
    int res = n - 1;
    for (int i = 2; i < n; i++) {
        if (gcd(n, i) == 1) {
            cnt = 0;
            calc(n, i);
            res = min(res, cnt);
        }
    }
    cout << res << "\n";
}
