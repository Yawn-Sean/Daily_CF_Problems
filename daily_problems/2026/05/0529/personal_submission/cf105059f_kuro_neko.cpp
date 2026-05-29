#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define ld long double
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
constexpr ll MX = 2e5 + 5;
ld h[MX], pre[MX];
auto init = [] {
    h[0] = 0;
    rep(i, 1, MX - 1) h[i] = h[i - 1] + 1.0 / i;
    pre[0] = h[0];
    rep(i, 1, MX - 1) pre[i] = pre[i - 1] + h[i];
    return 0;
}();
void solve() {
    ll n;
    cin >> n;
    vector<ld> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ld ans = 0;
    rep(i, 0, n - 1) { ans += a[i] * (pre[n] - pre[n - i - 1] - pre[i]); }
    cout << fixed << setprecision(15) << ans / (1.0 * n * (n + 1) / 2) << endl;
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
