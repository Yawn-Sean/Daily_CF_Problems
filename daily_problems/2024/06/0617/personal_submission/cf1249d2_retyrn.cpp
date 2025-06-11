int n, k, mx;
using ai3 = array<int, 3>;

void solve() {
    cin >> n >> k;
    vector<ai3> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i + 1;
        mx = max(a[i][1], mx);
    }
    sort(all(a));
    vector<int> d(mx + 2, 0);
    priority_queue<pii> q;
    int sum = 0;
    vector<int> res;
    for (int i = 1, j = 0; i <= mx; i ++) {
        while (j < n and a[j][0] <= i and a[j][1] >= i) {
            q.emplace(a[j][1], a[j][2]);
            d[a[j][0]] += 1;
            d[a[j][1] + 1] -= 1;
            j ++;
        }
        sum += d[i];
        while (sum > k and sz(q)) {
            auto r = q.top().fi, id = q.top().se;
            q.pop();
            res.emplace_back(id);
            d[r + 1] += 1;
            sum -= 1;
        }
    }
    cout << sz(res) << endl;
    sort(all(res));
    cout << res << endl;
}