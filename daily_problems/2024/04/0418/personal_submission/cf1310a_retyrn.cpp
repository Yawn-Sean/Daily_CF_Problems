int n;

void solve() {
    cin >> n;
    vector<int> a(n), t(n);
    cin >> a >> t;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i ++) {
        mp[a[i]].push_back(t[i]);
    }
    
    priority_queue<int> q;
    ll sum = 0, res = 0;
    int idx = -1;
    
    for (auto it = mp.begin(); it != mp.end(); it ++) {
        idx = max(idx, it->fi);
        for (auto& x : it->se) {
            sum += x;
            q.push(x);
        }
        int mx = (it == prev(mp.end()) ? inf : next(it)->fi);
        while (sz(q) and idx < mx) {
            idx ++;
            sum -= q.top();
            q.pop();
            res += sum;
        }
    }
    cout << res << endl;
}