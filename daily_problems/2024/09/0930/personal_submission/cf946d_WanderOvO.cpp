/*
每天肯定优先翘最早或者最晚的课
假设只有 1 天，怎么翘课最好？
能否预处理出第 i 天翘 j 节课后最少上多少小时？设为 min_time[i][j]
先把第 i 天里面所有上课的小时拿出来，然后强行枚举最后剩下的第一节课和最后一节课
假设剩下 cnt 节课，则翘了 tot - cnt 节课，更新到 min_time[i][tot - cnt] 上
这个只需要 O(nm^2) 的枚举即可做到
如果能预处理出来，则可以 dp[i][j] 再表示前 i 天总共翘了 j 次课的最少上课时间，使用 O(nk^2) 的 DP
*/

int n, m, k;
string s[M];
int min_time[M][M], dp[M][M];

void solve1() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    vector<vector<int>> lessons(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '1') {
                lessons[i].pb(j);
            }
        }
    }
    memset(min_time, 0x3f, sizeof min_time);
    for (int i = 1; i <= n; i++) {
        if (lessons[i].size() <= k) {
            for (int j = lessons[i].size(); j <= k; j++) {
                min_time[i][j] = 0;
            }
        }
        for (int j = 0; j < lessons[i].size(); j++) {
            for (int t = j; t < lessons[i].size(); t++) {
                int cnt = t - j + 1;
                int skip_cnt = lessons[i].size() - cnt;
                min_time[i][skip_cnt] = min(min_time[i][skip_cnt], lessons[i][t] - lessons[i][j] + 1); 
            }
        }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int t = 0; t <= j; t++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][t] + min_time[i][j - t]);
            }
        }
    }
    cout << dp[n][k] << "\n";
}      
