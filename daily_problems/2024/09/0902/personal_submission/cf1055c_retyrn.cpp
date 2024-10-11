using ai3 = array<int, 3>;
vector<ai3> a(2);

void solve() {
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < 3; j ++) {
            cin >> a[i][j];
        }
    }
    if (a[0] > a[1]) swap(a[0], a[1]);
    int t = gcd(a[0][2], a[1][2]);
    int dis = (a[1][0] - a[0][0]) % t;
    int res = 0;
    chmax(res, min(a[0][1] - a[0][0] + 1 - dis, a[1][1] - a[1][0] + 1));
    dis = t - dis;
    chmax(res, min(a[1][1] - a[1][0] + 1 - dis, a[0][1] - a[0][0] + 1));
    cout << res << endl;
}