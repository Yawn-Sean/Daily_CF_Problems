#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long ans = 0LL;
        map<pair<int, int>, long long> mp;
        for (int i = 0; i < n; i++) {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            int dx = u - x, dy = v - y;
            if (dx == 0) {
                dy = dy > 0 ? 1 : -1;
            } else if (dy == 0) {
                dx = dx > 0 ? 1 : -1;
            } else {
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
            }
            auto it = mp.find({-dx, -dy});
            if (it != mp.end()) {
                ans += it->second;
            }
            mp[{dx, dy}]++;
        }
        cout << ans << "\n";
    }

    return 0;
}

