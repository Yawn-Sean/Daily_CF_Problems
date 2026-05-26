#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vvl dp(m + 1, vl(m + 1, LLONG_MIN / 3));
    dp[0][0] = 0;
    vi cnt1(m + 1), cnt2(m + 1);
    int tem = 0;
    rep(i, 0, n - 1) {
        if (a[i] == 0) {
            rep(j, 1, m) cnt1[j] += cnt1[j - 1];
            rep(j, 1, m) cnt2[j] += cnt2[j - 1];
            rep(j, 0, tem) {
                if (dp[j][tem - j] == LLONG_MIN / 3) continue;
                dp[j][tem - j] += cnt1[j] + cnt2[tem - j];
            }
            fill(all(cnt1), 0);
            fill(all(cnt2), 0);
            rep(j, 0, tem) {
                if (dp[j][tem - j] == LLONG_MIN / 3) continue;
                dp[j + 1][tem - j] = max(dp[j + 1][tem - j], dp[j][tem - j]);
                dp[j][tem - j + 1] = max(dp[j][tem - j + 1], dp[j][tem - j]);
            }
            tem++;
        } else if (a[i] > 0)
            cnt1[a[i]]++;
        else
            cnt2[-a[i]]++;
    }
    rep(j, 1, m) cnt1[j] += cnt1[j - 1];
    rep(j, 1, m) cnt2[j] += cnt2[j - 1];
    rep(j, 0, tem) {
        if (dp[j][tem - j] == LLONG_MIN / 3) continue;
        dp[j][tem - j] += cnt1[j] + cnt2[tem - j];
    }
    ll ans = 0;
    rep(i, 0, tem) ans = max(ans, dp[i][tem - i]);
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
