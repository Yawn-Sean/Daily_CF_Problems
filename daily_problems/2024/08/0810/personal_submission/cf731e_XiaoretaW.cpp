int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }

    vector<ll> dp(n);
    ll mx = pref[n];
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = mx;
        setmax(mx, pref[i] - dp[i]);
    }
    cout << dp[1] << '\n';

    return 0;
}
