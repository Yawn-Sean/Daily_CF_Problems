int n;
void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    // 如果有1, 那么就是非1的个数
    int cnt = 0;
    for (auto x : a) {
        cnt += (x == 1);
    }
    if (cnt > 0) {
        cout << n - cnt << endl;
        return;
    }

    int mn = inf;
    for (int i = 0; i < n; i ++) {
        int cur = a[i], len = 1;
        for (int j = i + 1; j < n and cur > 1; j ++) {
            cur = __gcd(cur, a[j]);
            len ++;
        }
        if (cur == 1) mn = min(mn, len);
    }
    if (mn == inf) {
        cout << -1 << endl;
        return;
    }
    cout << mn + n - 2 << endl;
}
int main() {
    FAST;
    solve();
    return 0;
}