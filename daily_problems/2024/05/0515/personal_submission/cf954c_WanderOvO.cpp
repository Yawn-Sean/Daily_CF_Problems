/*
行数越大越好，直接拉满，不影响结果
当第一次发生跳跃式的变化时，就确定了 y
然后只需验证一下这个 y 是否符合后面的即可
*/

int T;
LL n, a[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    LL x = 1e9, y = 1e9;
    for (int i = 2; i <= n; i++) {
        LL d = abs(a[i] - a[i - 1]);
        if (d == 0) {
            cout << "NO\n";
            return;
        } else if (d > 1) {
            y = d;
            break;
        }
    }
    for (int i = 2; i <= n; i++) {
        LL d = abs(a[i] - a[i - 1]);
        if (d != 1 && d != y) {
            cout << "NO\n";
            return;
        }
        if (d == 1) {
            if (a[i] > a[i - 1] && a[i - 1] % y == 0) {
                cout << "NO\n";
                return;
            }
            if (a[i] < a[i - 1] && a[i] % y == 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    cout << x << " " << y << "\n";
}             