/*
初始点需要自己枚举
考虑目前的状态是先手的人在 i 结点，后手的人在 j 结点，上一次走是走的 ch 这条边，问先手走的人能不能必胜
*/

int dp[M][M][27];
int n, m;
int w[M][M];

void calc(int i, int j, int last_ch) {
    if (dp[i][j][last_ch] >= 0) {
        return;
    }

    dp[i][j][last_ch] = 0;
    bool has_lose_state = false;
    for (int k = 1; k <= n; k++) {
        if (w[i][k] >= last_ch) {
            calc(j, k, w[i][k]);
            if (dp[j][k][w[i][k]] == 0) {
                has_lose_state = true;
            }
        }
    }
    if (has_lose_state) {
        dp[i][j][last_ch] = 1;
    }
}

void meibao() {
    cin >> n >> m;
    memset(w, -1, sizeof w);
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= m; i++) {
        int u, v;
        string s;
        cin >> u >> v >> s;
        w[u][v] = s[0] - 'a';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            calc(i, j, 0);
            if (dp[i][j][0] > 0) {
                cout << "A";
            } else {
                cout << "B";
            }
        }
        cout << "\n";
    }
}
