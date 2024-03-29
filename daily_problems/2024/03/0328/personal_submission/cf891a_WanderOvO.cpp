int n, a[N], st[N][13], lg[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int query(int l, int r) {
    int k = lg[r - l + 1];
    return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st[i][0] = a[i];
    }
    for (int i = 2; i < N; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    
    if (query(1, n) != 1) {
        cout << "-1\n";
        return;
    }
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            cnt++;
        }
    }
    if (cnt > 0) {
        cout << n - cnt << "\n";
        return;
    }
    
    int minlen;
    bool ok = false;
    for (int len = 1; len <= n && !ok; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (query(l, r) == 1) {
                ok = true;
                minlen = len;
                break;
            }
        }
    }
    cout << minlen + n - 2 << "\n";
}