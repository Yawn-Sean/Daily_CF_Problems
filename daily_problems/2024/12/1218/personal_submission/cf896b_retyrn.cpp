int n, m, c;

void solve() {
    cin >> n >> m >> c;
    vector<int> a(n);
    int zero = n;
    for (int i = 0; i < m and zero > 0; i ++) {
        int t;
        cin >> t;
        int ans = 0;
        if (t <= c / 2) {
            for (int j = 0; j < n; j ++) {
                if (!a[j] or a[j] > t) {
                    zero -= (a[j] == 0);
                    a[j] = t;
                    ans = j;
                    break;
                }
            }
        }
        else {
            for (int j = n - 1; j >= 0; j --) {
                if (!a[j] or a[j] < t) {
                    zero -= (a[j] == 0);
                    a[j] = t;
                    ans = j;
                    break;
                }
            }
        }
        cout << ans + 1 << endl;
        cout.flush();
    }
}