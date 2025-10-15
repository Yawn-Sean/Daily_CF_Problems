#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> pts(m);
    for (int i = 0; i < m; ++i) {
        cin >> pts[i].first >> pts[i].second;
    }

    map<tuple<int,int,i64>, int> mp;
    for (int i = 0; i < m; i++) {
        auto& [x1, y1] = pts[i];
        for (int j = 0; j < i; j++) {
            auto& [x2, y2] = pts[j];
            int dx = x2 - x1;
            int dy = y2 - y1;
            int g = gcd(dx, dy);
            dx /= g; dy /= g;

            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            mp[{dx, dy, i64(x1) * dy - i64(y1) * dx}]++;
        }
    }    

    vector<int> ans(n + 1);
    for (auto& [k, v]: mp) {
        auto& [dx, dy, b] = k;
        if (dy != 0 && b % dy == 0 && b / dy >= 1 && b / dy <= n) {
            ans[b / dy] = max(ans[b / dy], v);
        }
    }

    i64 res = 0;
    for (int i = 1; i <= n; i++) {
        res += sqrt(ans[i] * 2) + 1;
    }
    cout << res << '\n';
    return 0;
}
