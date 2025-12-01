#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
const int INF = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0;
    for (int p : a) ans += 1LL * p;
    ll tem = (ans - 1) / 2;
    vector<ll> prd(n + 1, 0);
    vector<ll> pre(n + 1, 0);
    vector<ll> dp(n + 1, 0);
    int cnt = 1;
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + 1LL * a[i];
    for (; cnt <= n && pre[cnt] <= tem; cnt++) {
        dp[cnt] = (cnt == 1 ? 1 : dp[cnt - 1] * 2) % INF;
        prd[cnt] = (prd[cnt - 1] + dp[cnt]) % INF;
    }
    int t = 1;
    for (int i = cnt; i <= n; i++) {
        while (pre[i] - pre[t] > tem) t++;
        dp[i] = (prd[i - 1] - prd[t - 1] + INF) % INF;
        prd[i] = (prd[i - 1] + dp[i]) % INF;
    }
    cout << dp[n] << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}