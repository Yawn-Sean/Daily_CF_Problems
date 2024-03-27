#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<char, int>> events(2 * n);
    for (auto& [t, d] : events) {
        cin >> t;
        if (t == '-') cin >> d;
    }

    vector<int> ans(n);
    int index = n - 1;
    auto solve = [&] () -> bool {
        set<int> prices;
        for (int i = 2 * n - 1; i >= 0; i--) {
            auto& [t, d] = events[i];
            if (t == '+') {
                if (prices.empty()) {
                    return false;
                }
                auto it = prices.begin();
                ans[index--] = *it;
                prices.erase(it);
            } else {
                if (!prices.empty() && *prices.begin() < d) {
                    return false;
                }
                prices.insert(d);
            }
        }
        return true;
    };

    if (solve()) {
        cout << "YES\n";
        for (auto& d : ans) {
            cout << d << " ";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}

