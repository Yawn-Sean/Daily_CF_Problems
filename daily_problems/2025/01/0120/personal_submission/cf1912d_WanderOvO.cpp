/*
val = a[m]a[m - 1]...a[1]a[0]
val = sum(a[i] * b^i)
如果要满足第一种规则，则说明高位的自然被 n 整除了，也就是说 n 能整除 b^k
b 如果包含了 n 中所有的素因子，则是可以做到的
如果要满足第二种规则，则说明 a[k] * b^k + ... + a[2 * k - 1] * b^(2 * k - 1)
和 a[k] * b^0 + ... + a[2 * k - 1] * b^(k - 1) 对 n 同余
也就是说 a * b^k 和 a 对 n 同余，这说明 b^k 模 n 余 1
如果要满足第三种规则，则说明 a[k] * b^k + ... + a[2 * k - 1] * b^(2 * k - 1)
和 -(a[k] * b^0 + ... + a[2 * k - 1] * b^(k - 1)) 对 n 同余
这说明 b^k 模 n 余 -1，也就是 n - 1
综上，本题考查的就是寻找一个 k，使得 b^k 模 n 的余数是 0/1/-1(n - 1)
只需要枚举 k 从 1 到 n 即可，然后 % n，之后肯定陷入模数循环了
*/

LL b, n;

void meibao() {
    cin >> b >> n;
    LL val = 1;
    for (int i = 1; i <= n; i++) {
        val *= b;
        val %= n;
        if (val == 0) {
            cout << "1 " << i << "\n";
            return;
        }
        if (val == 1) {
            cout << "2 " << i << "\n";
            return;
        }
        if (val == n - 1) {
            cout << "3 " << i << "\n";
            return;
        }
    }
    cout << "0\n";
}
