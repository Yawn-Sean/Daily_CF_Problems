/*
如果 n = 2^k - 1，则显然可以按照异或和为 n 去配对，每对都是 n，所以是 n * (n + 1)
如果 n != 2^k - 1，考虑最大的 k，使得 n > 2^k - 1，则 [2^k, n] 的最高位都是 1，和它们配的一定是最高位是 0 的下标
2^k 配 2^k - 1，2^k + 1 配 2^k - 2，2^k + 2 配 2^k - 3
*/

LL n, res[N];

int get_cnt(int x) {
    int res = 0;
    if (x == 0) return 1;
    while (x) {
        res++;
        x >>= 1;
    }
    return res;
}

void calc(int r) {
    if (r == 0) {
        res[0] = 0;
        return;
    }
    int len = get_cnt(r);
    int power = (1 << (len - 1));
    for (int i = power; i <= r; i++) {
        res[i] = power - (i - power + 1);
        res[power - (i - power + 1)] = i;
    }
    // power - (r - power + 1) - 1
    if (power - (r - power + 1) - 1 >= 0) {
        calc(power - (r - power + 1) - 1);
    }
}

void meibao() {
    cin >> n;
    calc(n);
    cout << n * (n + 1) << "\n";
    for (int i = 0; i <= n; i++) {
        cout << res[i] << " ";
    }
}
