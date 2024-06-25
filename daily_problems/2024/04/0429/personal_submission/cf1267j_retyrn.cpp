int n;

void solve() {
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        mp[x] ++;
    }
    
    int mn = n;
    for (auto [k, v] : mp) {
        mn = min(mn, v);
    }
    
    int res = n;
    for (int k = 2; k <= mn + 1; k ++) {
        int sum = 0;
        for (auto [_, v] : mp) {
            int p = (v + k - 1) / k;
            if ((k - 1) * p <= v) sum += p;
            else {
                sum = n;
                break;
            }
        }
        res = min(res, sum);
    }
    cout << res << endl;
}