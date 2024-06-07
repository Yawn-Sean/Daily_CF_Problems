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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 5), suf(n + 5);
    dp[n] = suf[n] = 1;
    for (int i = n - 1; i >= 1; --i) {
        dp[i] = (dp[i] + suf[i + 1]) % m;
        for (int j = 2; i * j <= n; ++j) {
            dp[i] = (dp[i] + suf[i * j] - suf[min(i * j + j, n + 1)]) % m;
        }
        suf[i] = (suf[i + 1] + dp[i]) % m;
    }
    cout << dp[1] << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
