/*
dp[i][j]: 前 i 个数，第 i 个数填 j 是否合法
*/
 
int T;
int n, a[N], from[N][6];
bool dp[N][6];
 
void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 5; i++) {
        dp[1][i] = true;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            for (int k = 1; k <= 5; k++) {
                if (a[i] == a[i - 1] && j != k && dp[i - 1][k]) {
                    dp[i][j] |= dp[i - 1][k];
                    from[i][j] = k;
                } 
                if (a[i] < a[i - 1] && j < k && dp[i - 1][k]) {
                    dp[i][j] |= dp[i - 1][k];
                    from[i][j] = k;
                }
                if (a[i] > a[i - 1] && j > k && dp[i - 1][k]) {
                    dp[i][j] |= dp[i - 1][k];
                    from[i][j] = k;
                }
            }
        }
    }
    for (int j = 1; j <= 5; j++) {
        if (dp[n][j]) {
            int cur_b = j, cur = n;
            vector<int> res;
            while (cur > 0) {
                res.pb(cur_b);
                cur_b = from[cur][cur_b];
                cur--;
            }
            reverse(res.begin(), res.end());
            for (auto val : res) {
                cout << val << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "-1\n";
}      
