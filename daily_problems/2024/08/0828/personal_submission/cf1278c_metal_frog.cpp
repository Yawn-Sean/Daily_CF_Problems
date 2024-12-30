void solve() {
    int n;
    cin >> n;
    vector<int> num(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        if (num[i] == 2) num[i] = -1;
    }
    unordered_map<int, int> mp;
    int tot = 0, rem = 0;
    for (int i = n; i < 2 * n; i++) tot += num[i];
    mp[tot] = 0;
    for (int i = n; i < 2 * n; i++) {
        int removed = i - n + 1;
        rem += num[i];
        if (mp.find(tot - rem) == mp.end()) {
            mp[tot - rem] = removed;
        }
    }
 
    int sum = 0, cur = 0, ans = 2 * n;
    for (int i = 0; i < n; i++) sum += num[i];
 
    for (int i = 0; i <= n; i++) {
        if (i != 0) {
            cur += num[n - i];
        }
        int remSum = sum - cur;
        if (mp.find(-remSum) != mp.end()) ans = min(ans, mp[-remSum] + i);
    }
    cout << ans << "\n";
}
