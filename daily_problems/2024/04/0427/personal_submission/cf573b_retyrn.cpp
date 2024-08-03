int n;

void solve() {
    cin >> n;
    vector<int> h(n);
    cin >> h;
    
    vector<int> res(n);
    for (int i = 0; i < n; i ++) {
        res[i] = h[i];
    }
    res[0] = res[n - 1] = 1;
    for (int i = 1; i < n; i ++) {
        res[i] = min(res[i - 1] + 1, res[i]);
    }
    for (int i = n - 2; i >= 0; i --) {
        res[i] = min(res[i + 1] + 1, res[i]);
    }
    cout << *max_element(all(res)) << endl;
}