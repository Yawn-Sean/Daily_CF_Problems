void solve() {
    int n;
    cin >> n;
    vector<int> ans(n * 2);
    for (int i = 0, num = 1; num <= n; num += 2, i++) {
        ans[i] = ans[i + n - num] = num;
    } 
    for (int i = n, num = 2; num <= n; num += 2, i++) {
        ans[i] = ans[i + n - num] = num;
    }
    ans[2 * n - 1] = n;
    for (int x: ans) cout << x << " ";
    cout << "\n";
}
