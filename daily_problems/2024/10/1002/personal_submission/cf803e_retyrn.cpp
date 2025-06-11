int n, k;
string s;

void solve() {
    cin >> n >> k;
    cin >> s;
    vector<vector<int>> f(n + 1, vector<int>(k * 2 + 1, 0));
    vector<vector<int>> from(n + 1, vector<int>(k * 2 + 1, -1));
    f[0][k] = 1;
    
    for (int i = 0; i < n; i ++) {
        for (int j = 1; j < k + k; j ++) {
            if (!f[i][j]) continue;
            if (s[i] == 'L' or s[i] == '?') {
                f[i + 1][j - 1] = 1;
                from[i + 1][j - 1] = j;
            }
            if (s[i] == 'W' or s[i] == '?') {
                f[i + 1][j + 1] = 1;
                from[i + 1][j + 1] = j;
            }
            if (s[i] == 'D' or s[i] == '?') {
                f[i + 1][j] = 1;
                from[i + 1][j] = j;
            }
        }
    }
    
    if (f[n][k + k]) {
        string res;
        int cur = k + k, t = n;
        while (t > 0) {
            int lst = from[t][cur];
            if (lst < cur) res += 'W';
            else if (lst == cur) res += 'D';
            else res += 'L';
            cur = lst;
            t --;
        }
        reverse(all(res));
        cout << res << endl;
        return;
    }
    
    if (f[n][0]) {
        string res;
        int cur = 0, t = n;
        while (t > 0) {
            int lst = from[t][cur];
            if (lst < cur) res += 'W';
            else if (lst == cur) res += 'D';
            else res += 'L';
            cur = lst;
            t --;
        }
        reverse(all(res));
        cout << res << endl;
        return;
    }
    cout << "NO" << endl;
}