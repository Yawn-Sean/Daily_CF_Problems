int main() {
    int n, a, b, k;
    string s;
    cin >> n >> a >> b >> k >> s;
    vector<pair<int, int>> c;
    vector<int> ans;
    vector<int> pr(n + 1, 0);
    for (int i = 0; i < n; i ++) {
        if (s[i] == '0') pr[i + 1] = pr[i];
        else pr[i + 1] = i + 1; 
        if (s[i] == '1' && i) {
            c.push_back({i - pr[i], pr[i] + 1});
        }
    }
    if (s.back() == '0') {
        c.push_back({n - pr[n], pr[n] + 1});
    }
    sort(c.begin(), c.end());
    int now = 0;
    for (int i = 0; i < c.size(); i ++) {
        int cnt = c[i].first / b;
        if (a - cnt <= 0) {
            for (int j = b + c[i].second - 1; (c[i].first - (j - b - c[i].second + 1)) / b >= a; j += b) ans.push_back(j);
            now = i + 1;
            a = 1;
            // break;
        } else {
            a -= c[i].first / b;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << ' ';
    }
    // for (int i = now; i < c.size(); i ++) {

    // }
    return 0;
}
