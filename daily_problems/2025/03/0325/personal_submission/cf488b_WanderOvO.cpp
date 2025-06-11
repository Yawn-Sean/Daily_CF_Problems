/*
判断 x[1] + x[2] + x[3] + x[4], 2 * x[2] + 2 * x[3], 4 * (x[4] - x[1]) 是否相等
=>
x[1] - x[2] + x[3] - x[4] = 0
2 * x[1] + x[2] + x[3] - 2 * x[4] = 0
n = 0，一定可以，1 1 3 3
n = 1，假设极差是 d，最小的就是给出来的这个，叫做 a，并且钦定最小的两个数相等，最大的两个数相等
则只要 4 * d = 4 * a + 2 * d 即可，即 d = 2 * a 即可，所以就是 a, a, a + d, a + d
n = 4，代入方程检验是否符合题意即可
n = 2 和 3 还是太麻烦了，是否还有别的方法？
由于给的数都是 500 以内的，所以尝试直接枚举即可
*/

LL n, x[5];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);
    if (n == 0) {
        cout << "YES\n1\n1\n3\n3\n";
    } else if (n == 1) {
        cout << "YES\n";
        cout << x[1] << "\n" << 3 * x[1] << "\n" << 3 * x[1] << "\n";
    } else if (n == 2) {
        for (int i = 1; i <= 2000; i++) {
            for (int j = 1; j <= 2000; j++) {
                int a[5];
                a[1] = x[1];
                a[2] = x[2];
                a[3] = i;
                a[4] = j;
                sort(a + 1, a + 5);
                if (a[1] - a[2] - a[3] + a[4] == 0 && 
                    2 * a[1] + a[2] + a[3] - 2 * a[4] == 0) {
                    cout << "YES\n";
                    cout << i << "\n" << j << "\n";
                    return;
                }
            }
        }
        cout << "NO\n";
    } else if (n == 3) {
        for (int i = 1; i <= 2000; i++) {
            int a[5];
            a[1] = x[1];
            a[2] = x[2];
            a[3] = x[3];
            a[4] = i;
            sort(a + 1, a + 5);
            if (a[1] - a[2] - a[3] + a[4] == 0 && 
                2 * a[1] + a[2] + a[3] - 2 * a[4] == 0) {
                cout << "YES\n";
                cout << i << "\n";
                return;
            }
        }
        cout << "NO\n";
    } else {
        LL res1 = x[1] - x[2] - x[3] + x[4], res2 = 2 * x[1] + x[2] + x[3] - 2 * x[4];
        if (res1 == res2 && res1 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
