#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
const ll INF = 1LL << 60;
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<pii> seg; seg.emplace_back(x, x);
    vector<ll> pos; pos.emplace_back(x);
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        seg.emplace_back(l, r);
        pos.emplace_back(l);
        pos.emplace_back(r);
    }
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());
    int len = sz(pos);
    vector<ll> dp1(len, INF);
    vector<ll> dp2(len, INF);
    int posx = lower_bound(all(pos), x) - pos.begin();
    dp1[posx] = 0;
    for (int i = 1; i <= n; i++) {
        fill(all(dp2), INF);
        ll prefmin = INF;
        for (int j = 0; j < len; j++) {
            ll dis = min(abs(seg[i].first - pos[j]), abs(seg[i].second - pos[j]));
            if (pos[j] >= seg[i].first && pos[j] <= seg[i].second) dis = 0;
            prefmin = min(prefmin, dp1[j] - pos[j]);
            dp2[j] = min(dp2[j], prefmin + dis + pos[j]);
        } 
        ll suffixmin = INF;
        for (int j = len - 1; j >= 0; j--) {
            ll dis = min(abs(seg[i].first - pos[j]), abs(seg[i].second - pos[j]));
            if (pos[j] >= seg[i].first && pos[j] <= seg[i].second) dis = 0;
            suffixmin = min(suffixmin, dp1[j] + pos[j]);
            dp2[j] = min(dp2[j], suffixmin + dis - pos[j]);
        }
        swap(dp1, dp2);
    } 
    ll ans = INF;
    for (int i = 0; i < len; i++) {
        ans = min(ans, dp1[i]);
    }
    cout << ans << endl;
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    solve();
}
