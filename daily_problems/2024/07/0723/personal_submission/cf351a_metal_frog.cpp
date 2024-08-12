#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

const int N = 4005;
int dp[N][N];
 
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> delta(2 * n);
    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i < 2 * n; i++) {
        int tmp;
        scanf("%d.%d", &tmp, &delta[i]);
    }
    dp[0][0] = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            int cel = dp[i][j] + ((1000 - delta[i]) % 1000);
            int flo = dp[i][j] - delta[i];
            if (abs(cel) < abs(dp[i + 1][j + 1])) {
                dp[i + 1][j + 1] = cel;
            }
            if (abs(flo) < abs(dp[i + 1][j])) {
                dp[i + 1][j] = flo;
            }
        }
    }
    dp[2 * n][n] = abs(dp[2 * n][n]);
    double ans = double(dp[2 * n][n]) / 1000.000;
    printf("%.3lf\n", ans);
}
