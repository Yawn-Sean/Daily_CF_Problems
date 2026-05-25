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
struct node {
    ll d, p, c;
    ll lx, rx, ly, ry;
};
void solve() {
    int n;
    cin >> n;
    vector<node> ma(n);
    rep(i, 0, n - 1) { cin >> ma[i].d >> ma[i].p >> ma[i].c >> ma[i].lx >> ma[i].rx >> ma[i].ly >> ma[i].ry; }
    int mask = (1 << n);
    vl tem(mask);
    rep(i, 1, mask - 1) {
        rep(j, 0, n - 1) {
            if (i >> j & 1) tem[i] += ma[j].c;
        }
    }
    vector<double> dp(mask, -DBL_MAX / 3);
    dp[0] = 0;
    double ans = 0.0;
    rep(i, 1, mask - 1) {
        rep(j, 0, n - 1) {
            if ((i >> j & 1) == 0) continue;
            if (tem[i] > ma[j].d) continue;
            if (dp[i ^ (1 << j)] == -DBL_MAX / 3) continue;
            double tem2 = ((double)ma[j].lx + ma[j].rx) / 2.0;
            double tem3 = 0.0;
            if (ma[j].ly == ma[j].ry) {
                if (tem[i] <= ma[j].ry) tem3 = 1.0;
            } else {
                if (tem[i] <= ma[j].ly)
                    tem3 = 1.0;
                else if (tem[i] >= ma[j].ly && tem[i] <= ma[j].ry)
                    tem3 = ((double)ma[j].ry - tem[i]) / ((double)ma[j].ry - ma[j].ly);
            }
            dp[i] = max(dp[i], dp[i ^ (1 << j)] + ma[j].p + tem3 * tem2);
        }
        ans = max(ans, dp[i]);
    }
    cout << fixed << setprecision(12) << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
