#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    int n;
    cin >> n;
    vector<pair<double, int>> a(n);
    vector<pair<double, int>> b(n);
    auto f = [&](int x1, int y1, int x2, int y2) {
        return sqrt(1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2));
    };
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        double dis = f(x, y, tx, ty);
        a[i] = {f(x, y, ax, ay) - dis, i};
        b[i] = {f(x, y, bx, by) - dis, i};
        ans += dis * 2;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    double tmp = min(a[0].first, b[0].first);
    if (a.front().second == b.front().second) {
        tmp = min({tmp, a[0].first + b[1].first, a[1].first + b[0].first});
    } else {
        tmp = min(tmp, a[0].first + b[0].first);
    }
    cout << fixed << setprecision(15) << ans + tmp << endl;
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