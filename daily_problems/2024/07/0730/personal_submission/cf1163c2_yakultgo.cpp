#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    set<array<int, 3>> lines;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int dx = a[i].first - a[j].first;
            int dy = a[i].second - a[j].second;
            int gc = gcd(dx, dy);
            dx /= gc;
            dy /= gc;
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            int b = a[i].first * dy - a[i].second * dx;
            lines.insert({dx, dy, b});
        }
    }
    n = lines.size();
    ll ans = 1ll * n * (n - 1) / 2;
    map<pair<int, int>, int> mp;
    for (auto [x, y, _] : lines) {
        ans -= mp[{x, y}];
        mp[{x, y}]++;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}