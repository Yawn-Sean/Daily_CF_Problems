/*
感觉应该买最便宜的那些，但是不一定每次都使用技能白嫖 k - 1 个
假设能买到的最贵的是第 i 个，则从贵的开始用技能买
能否算一下买前 i 个物品至少花多少钱？
dp[i] = dp[i - k] + a[k]
dp[i] = dp[i - 1] + a[k]
*/

int T;
int n, p, k, a[N], dp[N];

void solve1() {
    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < k; i++) {
        dp[i] = dp[i - 1] + a[i];
    }
    for (int i = k; i <= n; i++) {
        dp[i] = min(dp[i - 1], dp[i - k]) + a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] <= p) {
            res = i;
        }
    }
    cout << res << "\n";
}            