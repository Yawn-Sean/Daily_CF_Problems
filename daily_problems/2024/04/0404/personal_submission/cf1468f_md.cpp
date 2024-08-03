#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef std::pair<int, int> pii;

void solve() {
    int n;
    cin >> n;

    std::map<pii, int> cnt;
    i64 ret = 0;
    for (int i = 0; i < n; ++i) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        auto dx = u - x;
        auto dy = v - y;
        auto gcd = abs(__gcd(dx, dy));
        dx /= gcd;
        dy /= gcd;
        ret += cnt[{-dx, -dy}];
        ++cnt[{dx, dy}];
    }
    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}