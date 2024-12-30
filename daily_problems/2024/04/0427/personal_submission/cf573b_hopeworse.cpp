
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int mins = -1;
 
    ans[1] = 1;
    for (int i = 2; i <= n; i++) {
        ans[i] = min(arr[i], ans[i - 1] + 1);
 
    }
    ans[n] = 1;
    for (int i = n - 1; i; i--) {
        ans[i] = min({ans[i], ans[i + 1] + 1});
    }
    for (int i = 1; i <= n; i++) {
        mins = max(mins, ans[i]);
    }
    debug(ans);
    cout << mins << endl;
}
