/*
分母的选择很有限，必须是 n 的非 1 非 n 因数，所以素数的情况必然是翡的
合数的情况，先做因数分解，把因数都找出来
假设一个因数是 k，说明选这个东西能得到 n / k 的分子
相当于有若干类因数，每类因数可以看成无限个，每类因数有自己的价值，要求价值之和是 n - 1，看是否有解
1e9 以内的数，约数个数最多也就 1000 左右，但是值域太大了，做不了完全背包
观察已经构造出来的结果，是否一定可以用两个数做呢？这两个分母好像还是互素的
*/

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void meibao() {
    LL n;
    cin >> n;
    LL root = sqrt(n);
    for (int i = 2; i <= root; i++) {
        if (n % i == 0) {
            if (gcd(i, n / i) == 1) {
                cout << "YES\n2\n";
                for (LL j = 1; j < i; j++) {
                    LL r = n - 1 - j * n / i;
                    if (r % i == 0) {
                        cout << j << " " << i << "\n";
                        cout << r / i << " " << n / i << "\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";
}
