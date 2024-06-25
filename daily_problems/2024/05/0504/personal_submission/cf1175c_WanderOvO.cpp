int T;
int n, k, a[N];

void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    int res = INF;
    int ans = 0;
    for (int i = 1; i + k <= n; i++) {
        int j = i + k;
        int mid = (a[i] + a[j]) / 2;
        if (max(mid - a[i], a[j] - mid) < res) {
            res = max(mid - a[i], a[j] - mid);
            ans = mid;
        }
    }
    cout << ans << "\n";
}  