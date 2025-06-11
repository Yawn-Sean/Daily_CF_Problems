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
const int mod = 998244353;

void solve() {
    int n, cnt = 0, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    ranges::sort(a);
    vector<int> dp(5001);
    dp[0] = 1;
    for (int ai : a) {
        for (int i = cnt; ~i; --i) {
            if (dp[i]) {
                ans = (ans + dp[i] * max((i + ai + 1) / 2, ai)) % mod;
                dp[i + ai] = (dp[i + ai] + dp[i]) % mod;
            }
        }
        cnt += ai;
    }
    cout << ans << endl;
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
