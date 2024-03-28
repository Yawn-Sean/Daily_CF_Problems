int n, U;

void solve() {
    cin >> n >> U;
    vector<int> a(n);
    // j = i + 1
    // 1 - (Ei+1 - Ei) / (Ek - Ei)
    // 枚举i, 取最远的k
    cin >> a;
    double res = -1.0;
    for (int i = 0, k = 2; i < n - 1; i ++) {
        int j = i + 1;
        while (k + 1 < n and a[k + 1] - a[i] <= U) {
            k ++;
        }
        if (k > j and a[k] - a[i] <= U) {
            res = max(res, 1.0 * (a[k] - a[j]) / (a[k] - a[i]));
        }
    }
    if (res < -0.5) {
        cout << -1 << endl;
    }
    else {
        cout << res << endl;
    }
}
int main() {
    FAST;
    // Tsolve();
    solve();
}