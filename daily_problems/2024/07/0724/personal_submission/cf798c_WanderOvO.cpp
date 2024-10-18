/*
gcd(a[i] - a[i + 1], a[i] + a[i + 1]) = gcd(a[i] + a[i + 1], 2 * a[i + 1])
= gcd(a[i] + a[i + 1], 2 * a[i])
所以一定能整除 2 * a[i] 和 2 * a[i + 1]
猜测最后所有数都得变成偶数才行
假如当前和下一个数字是奇数和偶数，则需要操作两次才能都变成偶数
假如当前和下一个数字都是奇数，则只需要操作一次
1 2 3 4
-1 3 3 4
-4 2 3 4
-4 2 -1 7
-4 2 -8 6
*/

int T;
LL n, a[N];

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve1() {
    cin >> n;
    LL origin_g;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    origin_g = gcd(a[1], a[2]);
    for (int i = 3; i <= n; i++) {
        origin_g = gcd(origin_g, a[i]);
    }
    if (origin_g != 1) {
        cout << "YES\n0\n";
        return;
    }
    
    LL res = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] % 2) {
            if (a[i + 1] % 2) {
                res += 1;
                a[i + 1] = 2;
            } else {
                res += 2;
                a[i + 1] = 2;
            }
            a[i] = 2;
        }
    }
    if (a[n] % 2) {
        res += 2;
    }
    cout << "YES\n";
    cout << res << "\n";
}            
