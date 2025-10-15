#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    int n, t;
    double p;
    cin >> n >> p >> t;
    vector<vector<double>> dp(t+1, vector<double>(n+1));
    // dp[i][j] -> 第i秒后电梯里有j人的概率 j<=i
    dp[0][0] = 1;
    for(int i=1; i<=t; i++) {
        dp[i][0] = dp[i-1][0] * (1-p);
        for(int j=1; j<=min(i, n); j++) {
            if(j == n) dp[i][j] = dp[i-1][j-1] * p + dp[i-1][j];
            else dp[i][j] = dp[i-1][j-1] * p + dp[i-1][j] * (1-p);
        }
    }
    double res = 0;
    for(int j=1; j<=n; j++)
        res += dp[t][j] * j;
    cout << res << endl;
}
