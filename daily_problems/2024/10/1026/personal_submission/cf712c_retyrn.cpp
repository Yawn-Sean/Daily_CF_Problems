int a, b;

void solve() {
    cin >> a >> b;
    int res = 0;
    vector<int> v(3, b);
    while (v[0] < a or v[1] < a or v[2] < a) {
        sort(all(v));
        int t = min(v[1] + v[2] - 1, a);
        v[0] = t;
        res += 1;
    }
    cout << res << endl;
}