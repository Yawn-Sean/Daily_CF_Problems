/*
n * n 的矩阵，每个 m * m 子矩阵必须至少包含一个 0
手玩 n = 5, m = 1-5 的情况，发现需要 (n / m) * (n / m) 个
是否存在 n, m, 满足 n * n - (n / m) * (n / m) = x
(n + n / m) * (n - n / m) = x
对 x 因数分解成 v1 * v2, v1 < v2，求解 a + b = v2, a - b = v1, a = (v1 + v2) / 2，b = v2 - a, v1 + v2 偶数
n = a 一定没问题，n / m = b 能否做到？是否存在 m，使得 n / m = b？
先设 m = n / b，然后验证 n / m 是否为 b
*/

LL x;

void meibao() {
    cin >> x;
    if (x == 0) {
        cout << "1 1\n";
        return;
    }
    LL root = sqrt(x);
    for (int i = 1; i <= root; i++) {
        if (x % i == 0) {
            LL v1 = i, v2 = x / i;
            if (v1 > v2) {
                swap(v1, v2);
            }
            if ((v1 + v2) % 2 == 0) {
                LL a = (v1 + v2) / 2, b = v2 - a;
                if (b != 0) {
                    LL n = a, n_div_m = b, m;
                    m = n / n_div_m;
                    if (m != 0 && n / m == n_div_m) {
                        cout << n << " " << m << "\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "-1\n";
}
