#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    int n, a, b, c;
    cin >> n;
    vector<tuple<ll, ll, ll>> ma(n);
    rep(i, 0, n - 1) {
        cin >> a >> b >> c;
        ma[i] = make_tuple(a, b, c);
    }
    vi res(n);
    vvi ma2(n);
    vvi ma3(n);
    vi deg(n);
    vi deg2(n);
    rep(i, 0, n - 1) {
        rep(j, i + 1, n - 1) {
            ll a1 = get<0>(ma[i]), a2 = get<0>(ma[j]);
            ll b1 = get<1>(ma[i]), b2 = get<1>(ma[j]);
            ll c1 = get<2>(ma[i]), c2 = get<2>(ma[j]);
            if (a1 != a2 && (b1 - b2) * (b1 - b2) - 4 * (a1 - a2) * (c1 - c2) < 0) {
                if (a1 > a2) {
                    ma2[i].push_back(j);
                    ma3[j].push_back(i);
                    deg[j]++;
                    deg2[i]++;
                } else {
                    ma2[j].push_back(i);
                    ma3[i].push_back(j);
                    deg[i]++;
                    deg2[j]++;
                }

            } else if (a1 == a2 && b1 == b2 && c1 != c2) {
                if (c1 > c2) {
                    ma2[i].push_back(j);
                    ma3[j].push_back(i);
                    deg[j]++;
                    deg2[i]++;
                } else {
                    ma2[j].push_back(i);
                    ma3[i].push_back(j);
                    deg[i]++;
                    deg2[j]++;
                }
            }
        }
    }
    vi dp(n);
    vi fdp(n);
    auto bfs = [&](this auto&& bfs, vvi& ma, vi& deg, vi& dp) -> void {
        queue<int> q;
        rep(i, 0, n - 1) {
            if (deg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (int& p : ma[node]) {
                dp[p] = max(dp[p], dp[node] + 1);
                if (--deg[p] == 0) {
                    q.push(p);
                }
            }
        }
    };
    bfs(ma2, deg, dp);
    bfs(ma3, deg2, fdp);
    rep(i, 0, n - 1) cout << dp[i] + fdp[i] + 1 << ' ';
    cout << endl;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
