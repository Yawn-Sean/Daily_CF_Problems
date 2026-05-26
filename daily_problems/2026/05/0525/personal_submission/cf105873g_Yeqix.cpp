#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    i64 n, A;
    cin >> n >> A;

    if (A < (n - 1) / 2) {
        cout << "No\n";
        return;
    }

    vector<array<int, 2>> ans;
    auto add = [&](int x, int y) -> void { ans.push_back({x, y}); };

    int x = 0, y = 0;
    while (n > 1 + !(n & 1)) {
        add(x, y), add(x + 1, y);
        if (x >= 0) {
            x--;
        } else {
            x++;
        }
        y++, A--;
        n -= 2;
    }

    if (n & 1) {
        add(x + 1, y + 2 * A + 1);
    } else {
        add(x, y + A), add(x + 1, y + A);
    }

    cout << "Yes\n";
    int m = ans.size();
    for (int i = 0; i < m; i += 2) {
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
    for (int i = m - 1 - (m & 1); i >= 0; i -= 2) {
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}