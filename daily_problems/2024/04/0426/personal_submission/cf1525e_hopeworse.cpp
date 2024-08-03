
void solve() {
    int n, m;
    cin >> n >> m;
    int tmp = 1;
    for (int i = 1; i <= n; i++) {
        tmp = (tmp * i) % mod;
    }
    tmp = inv(tmp);
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
//    vector<vector<int>> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; i++) {
        vector<int> dis;
        dis.emplace_back(1);
        for (int j = 1; j <= n; j++) {
            dis.emplace_back(arr[j][i]);
        }
        sort(dis.begin(), dis.end());
        int le = 1;
        debug(dis);
        for (int j = 1; j <= n; j++) {
            if (dis[j] - j < 0)le = 0;
            else {
                le *= (dis[j] - j);
                le %= mod;
            }
        }
        debug(le, tmp);
        ans = (ans + 1 - (le * tmp) % mod + mod) % mod;
    }
    cout << ans << endl;
}
