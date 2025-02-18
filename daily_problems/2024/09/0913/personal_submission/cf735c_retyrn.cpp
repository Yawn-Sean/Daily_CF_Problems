ll n;
ll f[100];

void solve() {
    cin >> n;
    f[0] = 0LL, f[1] = 1LL, f[2] = 2LL;
    for (int i = 3; i <= 90; i ++) {
        f[i] = f[0] * 2 + i;
        for (int j = 1; j <= i - 2; j ++) {
            f[i] += f[j];
        }
    }
    for (int i = 1; i < 90; i ++) {
        if (f[i] > n - 1) {
            cout << i - 1 << endl;
            return;
        }
    }
}