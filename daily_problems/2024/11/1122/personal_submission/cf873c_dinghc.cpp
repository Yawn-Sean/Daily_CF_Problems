#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto calc = [&] (int j) {
        pair<int, int> res{0, 0};
        for (int u = 0, d = 0, curr = 0, chg = 0; u < n; u++) {
            curr += a[u][j] == 1;
            if (u - d + 1 > k) {
                curr -= a[d][j] == 1;
                chg += a[d][j] == 1;
                d++;
            }
            res = max(res, pair<int, int> {curr, -chg});
        }
        return res;
    };
    int ans1 = 0, ans2 = 0;
    for (int j = 0; j < m; j++) {
        auto [score, chgs] = calc(j);
        ans1 += score, ans2 -= chgs;
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}

