#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

/*
考虑前 i 个数有多少种合法分割
我们还关心到底分成了多少段，所以还要记录分成的段数 j
dp[i][j] += dp[k][j - 1]，if (s[i] - s[k]) % j == 0
如何快速找到所有可行的 k 呢？
(s[i] - s[k]) % j == 0，其实就是 s[i] % j == s[k] % j
假设我们已经算好了 dp[i][j]，则其可能贡献给某个 dp[][j + 1]
所以我们关心 s[i] % (j + 1) 的值
我们开一个二维数组，c[i][j] 表示 s[t] % i = j 的那些 dp[t][i - 1] 的和
我们把 dp[i][j] 的结果，加到 c[j + 1][s[i] % (j + 1)] 上
回过头来，dp[i][j] 是怎么算好的呢？其实就是利用了 c[j][s[i] % j] 的结果

如何初始化呢?
似乎只有 dp[0][0] = 1, 以及 c[1][0] = 1;

注意空间，无脑开 long long 且不压缩空间会炸掉
*/

void solve() {
    int n;
    cin >> n;
    vector<LL> s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        s[i] = i;
        s[i] += s[i - 1];
    }
    
    int mod = 1e9 + 7;
    
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    vector<vector<int>> c(n + 2, vector<int>(n + 2, 0));
    
    dp[0][0] = 1;
    c[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = c[j][s[i] % j];
            // cout << "dp(" << i << ", " << j << "): " << dp[i][j] << "\n";
        }
        for (int j = 1; j <= i; j++) {
            c[j + 1][s[i] % (j + 1)] += dp[i][j];
            c[j + 1][s[i] % (j + 1)] %= mod;
        }
    }
    LL res = 0;
    for (int j = 1; j <= n; j++) {
        res += dp[n][j];
        res %= mod;
    }
    cout << res << "\n";
}

int main() {
    #ifdef LOCAL_TEST
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
