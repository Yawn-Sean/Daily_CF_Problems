#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    int n;
    cin >> n;
    vector<string> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        f[i] = " " + f[i];
    }

    vector<array<int, 2>> ans, ans2;
    for (int i = 1; i <= n; i++) {
        int Is = 0, Is2 = 0;
        for (int j = 1; j <= n; j++) {
            if (f[i][j] == 'H' && !Is) {
                Is = 1;
                ans.push_back({i, j});
            }
            if (f[j][i] == 'V' && !Is2) {
                ans2.push_back({j, i});
                Is2 = 1;
            }
        }
        if (!Is) {
            for (int j = 1; j <= n; j++) {
                ans.push_back({i, j});
            }
        }
        if (!Is2) {
            for (int j = 1; j <= n; j++) {
                ans2.push_back({j, i});
            }
        }
    }

    if (ans.size() > ans2.size()) {
        swap(ans, ans2);
    }

    cout << ans.size() << "\n";
    for (const auto& [l, r] : ans) {
        cout << l << " " << r << "\n";
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