void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 1; i <= k + 1; i++) {
        cout << "? ";
        for (int j = 1; j <= k + 1; j++) {
            if (j == i)continue;
            cout << j << " ";
        }
        cout << endl;
        int x, y;
        cin >> x >> y;
        mp[y]++;
    }
    int maxs = -1;
    for (auto [i, j]: mp) {
        maxs = max(maxs, i);
    }
    cout << "! " << mp[maxs] << endl;
}
