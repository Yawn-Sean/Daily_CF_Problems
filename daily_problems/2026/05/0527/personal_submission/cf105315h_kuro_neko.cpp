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
    ll n, k;
    cin >> n >> k;
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    sort(all(ma), [&](const pll& x, const pll& y) { return x.second < y.second; });
    priority_queue<ll, vl, greater<>> q;
    ll tem = 0;
    ll ans = LLONG_MIN;
    rep(i, 0, n - 1) {
        tem += ma[i].first;
        q.push(ma[i].first);
        if (sz(q) < k) continue;
        if (sz(q) > k) {
            auto node = q.top();
            q.pop();
            tem -= node;
            ans = max(ans, tem - ma[i].second);
        } else
            ans = max(ans, tem - ma[i].second);
    }
    cout << ans << endl;
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
