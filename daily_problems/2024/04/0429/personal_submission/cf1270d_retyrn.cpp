int n, k;

void solve() {
    cin >> n >> k;
    map<int, int> mp;
    
    for (int i = 1; i <= k + 1; i ++) {
        cout << '?' << ' ';
        for (int j = 1; j <= k + 1; j ++) {
            if (i == j) continue;
            cout << j << ' ';
        }
        cout << endl;
        cout.flush();
        
        int x, y;
        cin >> x >> y;
        mp[y] ++;
    }
    
    cout << '!' << ' ' << mp.rbegin()->se << endl;
    cout.flush();
}