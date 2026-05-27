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
    ll n, m, x, y, z;
    cin >> n >> m;
    vector<trl> ma;
    rep(i, 1, m) {
        cin >> x >> y >> z;
        ma.emplace_back(x, y, z);
    }
    auto check = [&](int x, int y) -> int { return x * n + y; };
    vector<vector<pll>> ma2(n * n + 1);
    rep(i, 1, n - 1) ma2[n * n].emplace_back(check(0, i), 0);
    rep(i, 1, n - 1) {
        for (auto& [x, y, z] : ma) {
            ma2[check(x, i)].emplace_back(check(y, i - 1), z * i);
        }
    }
    priority_queue<pll, vector<pll>, greater<>> q;
    vl dis(n * n + 1, LLONG_MAX / 3);
    q.emplace(0, n * n);
    dis[n * n] = 0;
    while (!q.empty()) {
        auto [dis_x, x] = q.top();
        q.pop();
        if (dis_x > dis[x]) continue;
        for (auto& [y, z] : ma2[x]) {
            ll dis_y = dis[x] + z;
            if (dis_y < dis[y]) {
                dis[y] = dis_y;
                q.emplace(dis[y], y);
            }
        }
    }
    vl res(n, LLONG_MAX / 3);
    rep(i, 1, n - 1) {
        rep(j, 0, n - 1) { res[i] = min(res[i], dis[check(i, j)]); }
    }
    rep(i, 1, n - 1) cout << (res[i] == LLONG_MAX / 3 ? -1 : res[i]) << ' ';
    cout << endl;
    return;
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
