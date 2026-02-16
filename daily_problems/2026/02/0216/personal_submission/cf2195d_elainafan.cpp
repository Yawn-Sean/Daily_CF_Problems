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
    int n;
    cin >> n;
    vl f(n);
    vl a(n);
    rep(i, 0, n - 1) cin >> f[i];
    ll tot = (f[0] + f[n - 1]) / (n - 1);
    ll tem = 0;
    rep(i, 0, n - 2) {
        a[i] = (tot - (f[i] - f[i + 1] + 2LL * tem)) / 2;
        tem += a[i];
    }
    a[n - 1] = tot;
    rep(i, 0, n - 2) a[n - 1] -= a[i];
    rep(i, 0, n - 1) cout << a[i] << ' ';
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
