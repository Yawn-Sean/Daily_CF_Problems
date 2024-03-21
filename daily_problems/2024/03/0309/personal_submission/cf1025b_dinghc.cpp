#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n;
    cin >> n;

    vector<pair<int64, int64>> g(n);
    for (auto&[a, b] : g) {
        cin >> a >> b;
    }

    set<int> factors;
    auto trial_div = [&] (int n) -> void {
        for (int64 d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                factors.insert(d);
                while (n % d == 0) {
                    n /= d;
                }
            }
        }
        if (n > 1) {
            factors.insert(n);
        }
    };

    trial_div(g[0].first);
    trial_div(g[0].second);
    for (int i = 1; i < n; i++) {
        auto&[a, b] = g[i];
        for (auto it = factors.begin(); it != factors.end();) {
            int x = *it;
            if (a % x != 0 && b % x != 0) {
                it = factors.erase(it);
            } else {
                it++;
            }
        }
    }

    if (factors.empty()) {
        cout << -1 << "\n";
    } else {
        cout << *factors.begin() << "\n";
    }

    return 0;
}
