#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

int n, k;
int dp[1005][1005][3];

int dfs(int x, int y, int to) {
    if (dp[x][y][to]) {
        return dp[x][y][to];
    }
    if (x == 1) {
        return dp[x][y][to] = 1;
    }
    if (y == n + 1 and to == 1) {
        return dp[x][y][to] = 1;
    }
    if (not y and not to) {
        return dp[x][y][to] = 1;
    }
    if (to == 1) {
        return dp[x][y][to] = (dfs(x - 1, y - 1, 0) + dfs(x, y + 1, to)) % mod;
    }
    return dp[x][y][to] = (dfs(x - 1, y + 1, 1) + dfs(x, y - 1, to))%mod;
}

void solve() {
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    cout << dfs(k, 1, 1) << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    int Test; cin >> Test; while (Test--)
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
