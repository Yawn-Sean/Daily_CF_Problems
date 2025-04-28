#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, x1, y1, x2, y2, x, y;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<pair<int, int>> idx(n);
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        idx[i] = {x, y};
    }
    vector<pair<int, int>> dis;
    for (auto& p : idx) {
        int tmp1 = (p.first - x1)*(p.first - x1) + (p.second - y1)*(p.second - y1);
        int tmp2 = (p.first - x2)*(p.first - x2) + (p.second - y2)*(p.second - y2);
        dis.emplace_back(tmp1, tmp2);
    }
    sort(dis.begin(), dis.end(), [&](auto& p1, auto&p2) {
        return p1.first < p2.first;
    });
    vector<int> mx2(n);
    mx2[n-1] = dis[n-1].second;
    for (int i = n-2; i >= 0; i--) {
        mx2[i] = max(mx2[i+1], dis[i].second);
    }
    int ans = mx2[0] + 0;
    for (int i = 0; i < n-1; ++i) {
        ans = min(ans, dis[i].first + mx2[i+1]);
    }
    ans = min(ans, dis[n-1].first + 0);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}