/*
只和询问长度有关系
*/

int T;
LL a[N], n, q;
LL s[N];

void solve1() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i + 1] - a[i];
    }
    a[n - 1] = 1e18;
    a[n - 1]++;
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    cin >> q;
    while (q--) {
        LL l, r;
        cin >> l >> r;
        LL length = r - l + 1;
        int pos = lower_bound(a, a + n, length) - a;
        // cout << s[pos - 1] << "\n";
        cout << s[pos] + (n - pos) * length << " ";
    }
}   
