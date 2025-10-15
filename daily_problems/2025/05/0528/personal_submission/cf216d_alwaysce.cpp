#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> pos(n + 2);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int v;
            cin >> v;
            pos[i].emplace_back(v);
        }
        sort(pos[i].begin(), pos[i].end());
    }

    for (auto&v: pos[n]) {
        pos[0].emplace_back(v);
    }
    for (auto&v: pos[1]) {
        pos[n+1].emplace_back(v);
    }

    auto get_count = [&](int l, int r, int i) {
        auto& p = pos[i];
        return upper_bound(p.begin(), p.end(), r) - lower_bound(p.begin(), p.end(), l);
    };
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int k = pos[i].size();
        for (int j = 0; j + 1 < k; j++) {
            int l = pos[i][j], r = pos[i][j + 1];
            
            int c1 = get_count(l, r, i - 1);
            int c2 = get_count(l, r, i + 1);
            if (c1 != c2) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
