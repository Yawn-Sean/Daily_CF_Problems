int n, k;
ll f[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        f[x] += 1;
    }
    ll sum = 0;
    // 枚举答案
    int j = 10000000;
    for (int i = 10000000; i > 0; i --) {
        while (j >= i * 2) {
            sum -= f[j];
            if (j & 1) {
                sum += f[j];
                f[j / 2 + 1] += f[j];
                f[j / 2] += f[j];
            }
            else f[j / 2] += f[j] * 2;
            j --;
        }
        sum += f[i];
        
        if (sum >= k) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}