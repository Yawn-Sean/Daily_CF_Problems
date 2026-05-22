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
    ll n, t;
    cin >> n >> t;
    vector<double> res(n);
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll tot = 0;
    ll ans = 0;
    priority_queue<pll, vector<pll>, greater<>> q;
    rep(i, 0, n - 1) {
        res[i] = 2;
        ans += 50;
        tot += a[i] / 2;
        q.emplace(a[i] / 6, i);
    }
    while (!q.empty()) {
        auto [x, y] = q.top();
        q.pop();
        if (tot + x > t) break;
        ans += 25;
        tot += x;
        if (res[y] == 2) {
            res[y] = 1.5;
            q.emplace(a[y] / 3, y);
        } else
            res[y] = 1;
    }
    cout << ans << endl;
    rep(i, 0, n - 1) cout << res[i] << ' ';
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
