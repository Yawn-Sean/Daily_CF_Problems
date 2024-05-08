int n;

void solve() {
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    map<int, int> mp, freq;
    int res = 0;
    
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        mp[x] ++;
        freq[mp[x]] ++;
        if (mp[x] * freq[mp[x]] == i + 1 and i + 1 < n) res = i + 2;
        else if (mp[x] * freq[mp[x]] == i) res = i + 1;
    }
    cout << res << endl;
}