#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

void solve() { 
    ll x0, y0, ax, ay, bx, by, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    vector<PLL> loc(1, {x0, y0});
    for (int i = 1; ; i++) {
        ll a = ax * loc[i - 1].first + bx;
        ll b = ay * loc[i - 1].second + by;
        if (a - xs + b - ys > t) break;
        loc.emplace_back(a, b);
    }
    int ans = 0;
    for (int i = 0, k; i < loc.size(); i++) {
        ll val = abs(xs - loc[i].first) + abs(ys - loc[i].second);
        for (int j = 0; j <= i; j++) {
            for (k = i; k < loc.size(); k++) {
                ll all_val = loc[k].first - loc[j].first + loc[k].second - loc[j].second;
                ll val_l = loc[i].first - loc[j].first + loc[i].second - loc[j].second;
                ll val_r = loc[k].first - loc[i].first + loc[k].second - loc[i].second;
                if (val + all_val + min(val_l, val_r) <= t) ans = max(ans, k - j + 1);
            }
        }
    }
    cout << ans << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
