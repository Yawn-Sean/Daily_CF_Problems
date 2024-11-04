void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        priority_queue<int> maxVal[4];
        for (int j = 0; j < m; j++) {
            int cost, val;
            cin >> cost >> val;
            maxVal[cost].push(val);
        }
        for (int cost = 1; cost < 4; cost++) {
            for (int j = 0; j < 3 && !maxVal[cost].empty(); j++) {
                int val = maxVal[cost].top();
                card[i][cost].emplace_back(val);
                maxVal[cost].pop();
            }
        }
    } 
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int cnt = 0; cnt < 10; cnt++) {
            if (dp[i][cnt] == -1) continue;
            //cout << i << " " << cnt << " " << dp[i][cnt] << endl;
            dp[i + 1][cnt] = max(dp[i + 1][cnt], dp[i][cnt]);
            if (card[i][3].size() != 0) {
                // take 3
                ll val = card[i][3].front();
                if (cnt == 9) val *= 2LL;
                int ncnt = (cnt + 1) % 10;
                dp[i + 1][ncnt] = max(dp[i + 1][ncnt], dp[i][cnt] + val);
            }
            if (card[i][2].size() != 0) {
                ll val = card[i][2].front();
                if (cnt == 9) val *= 2LL;
                int ncnt = (cnt + 1) % 10;
                dp[i + 1][ncnt] = max(dp[i + 1][ncnt], dp[i][cnt] + val);
                if (card[i][1].size() != 0) {
                    ll val2 = card[i][2].front(), val1 = card[i][1].front();
                    if (cnt == 9 || cnt == 8) {
                        val = 2LL * max(val2, val1) + min(val2, val1);
                    } else {
                        val = val2 + val1;
                    }
                    ncnt = (cnt + 2) % 10;
                    dp[i + 1][ncnt] = max(dp[i + 1][ncnt], dp[i][cnt] + val);
                }
            }
            if (card[i][1].size() != 0) {
                ll sum = accumulate(all(card[i][1]), 0LL);
                ll maxEle = *max_element(all(card[i][1]));
                ll num = sz(card[i][1]);
                if (num > 1) {
                    int ncnt = (cnt + 1) % 10;
                    ll val = maxEle;
                    if (cnt + 1 >= 10) {
                        val *= 2LL;
                    }
                    dp[i + 1][ncnt] = max(dp[i + 1][ncnt], dp[i][cnt] + val);
                }
                if (num > 2) {
                    int ncnt = (cnt + 2) % 10;
                    ll val = card[i][1][0] + card[i][1][1];
                    if (cnt + 2 >= 10) {
                        val += card[i][1][0];
                    }
                    dp[i + 1][ncnt] = max(dp[i + 1][ncnt], dp[i][cnt] + val);
                }
                if (cnt + num >= 10) {
                    ll val = sum + maxEle;
                    int ncnt = (cnt + num) % 10;
                    dp[i + 1][ncnt] = max(dp[i + 1][ncnt], dp[i][cnt] + val);
                } else {
                    ll val = sum;
                    int ncnt = (cnt + num % 10);
                    dp[i + 1][ncnt] = max(dp[i + 1][ncnt], dp[i][cnt] + val);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << "\n";
}
