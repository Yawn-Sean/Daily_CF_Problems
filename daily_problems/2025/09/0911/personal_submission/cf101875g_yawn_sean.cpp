#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> cars(n);
    for (auto &[x, y]: cars) cin >> x >> y;

    sort(cars.rbegin(), cars.rend());

    vector<pair<int, int>> stk;
    long double ans = 0;

    for (auto &[x, y]: cars) {
        while (!stk.empty()) {
            if (stk.back().second >= y) stk.pop_back();
            else if (stk.size() > 1) {
                auto [x1, y1] = stk[stk.size() - 1];
                auto [x2, y2] = stk[stk.size() - 2];

                if (1ll * (y - y2) * (x - x1) <= 1ll * (y - y1) * (x - x2)) stk.pop_back();
                else break;
            }
            else break;
        }

        if (!stk.empty()) {
            auto [x1, y1] = stk.back();
            ans = max(ans, - (long double)1 * (x - x1) / (y - y1));
        }

        stk.emplace_back(x, y);
    }

    cout << fixed << setprecision(10) << ans;

    return 0;
}