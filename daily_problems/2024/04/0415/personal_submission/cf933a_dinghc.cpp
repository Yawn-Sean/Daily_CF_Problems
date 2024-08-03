// Submission link: https://codeforces.com/contest/933/submission/256752551

int main() {
    int n;
    cin >> n;

    int dp[4]{};
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x == 1) {
            dp[0]++;
            dp[2] = max(dp[2] + 1, dp[1] + 1);
        } else {
            dp[1] = max(dp[1] + 1, dp[0] + 1);
            dp[3] = max(dp[3] + 1, dp[2] + 1);
        }
    }

    cout << max(max(dp[0], dp[1]), max(dp[2], dp[3])) << "\n";

    return 0;
}

