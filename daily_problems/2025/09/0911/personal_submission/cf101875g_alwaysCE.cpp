#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<pair<i64, i64>> cars(n);
    for (auto& [x, y] : cars) {
        cin >> x >> y;
    }
    sort(cars.begin(), cars.end());

    vector<pair<i64, i64>> stk; // (x, y)
    long double ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        auto [x, y] = cars[i];
        while (!stk.empty()) {
            if (stk.back().second >= y) {
                stk.pop_back();
            } else if (stk.size() > 1) {
                auto [x1, y1] = stk[stk.size() - 1];
                auto [x2, y2] = stk[stk.size() - 2];
                if (1ll * (y - y2) * (x - x1) <= 1ll * (y - y1) * (x - x2)) {
                    stk.pop_back();
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        if (!stk.empty()) {
            auto [x1, y1] = stk.back();
            ans = max(ans, static_cast<long double>(x1 - x) / (y - y1));
        }
        stk.emplace_back(x, y);
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
