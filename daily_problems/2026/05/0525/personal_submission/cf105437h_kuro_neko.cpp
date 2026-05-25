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
    string s;
    int n;
    cin >> n >> s;
    vector<pll> tem;
    int tem2 = 1;
    int las = 0;
    rep(i, 1, n - 1) {
        if (s[i] != s[i - 1]) {
            tem.emplace_back(las, tem2);
            tem2 = 1;
            las = i;
        } else
            tem2++;
    }
    if (tem2 != 0) tem.emplace_back(las, tem2);
    int m = sz(tem);
    ll ans = 0;
    rep(i, 0, m - 1) ans += tem[i].second * tem[i].second;
    ll ans2 = -1;
    rep(i, 0, m - 2) {
        auto [c1, l1] = tem[i];
        auto [c2, l2] = tem[i + 1];
        ll tem2 = (l1 - 1) * (l1 - 1) + 2 + (l2 - 1) * (l2 - 1) - l1 * l1 - l2 * l2;
        if (l1 == 1 && i >= 1 && s[tem[i - 1].first] == s[c2]) tem2 += 2 * tem[i - 1].second;
        if (l2 == 1 && i <= m - 3 && s[tem[i + 2].first] == s[c1]) tem2 += 2 * tem[i + 2].second;
        ans2 = max(ans2, ans + tem2);
    }
    cout << ans2 << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
