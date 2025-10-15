#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto&x: grid) { cin >> x; }

    vector<int> cur(n, 0), cnt(m + 1, 0);
    int ans = 0;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cur[i] = (grid[i][j] == '1') ? cur[i] + 1 : 0;
        }

        for (auto &x: cur) { ++cnt[x];}

        int c = 0;
        for (int j = m; j >= 0; j--) {
            c += cnt[j];
            ans = max(ans, c * j);
        }

        for (auto &x: cur) { --cnt[x];}
    }
    cout << ans << endl;
    return 0;
}
