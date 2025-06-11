int n;

void solve() {
    // 答案一定是出现过的数
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i ++) {
        mp[a[i]].push_back(i);
    }
    
    DSU dsu(n);
    int con = 0, sum = 0, mx = 0;
    int res = -1, rc = -1;
    for (auto& [val, vec] : mp) {
        for (auto x : vec) {
            con += 1;
            sum += 1;
            if (x - 1 >= 0 and a[x-1] <= val) con -= dsu.merge(x - 1, x);
            if (x + 1 < n and a[x+1] <= val) con -= dsu.merge(x, x + 1);
            chmax(mx, dsu.size(x));
        }
        
        if ((ll)con * mx == sum) {
            if (res < 0 or con > rc) res = val, rc = con;
        }
    }
    
    cout << res + 1 << endl;
}