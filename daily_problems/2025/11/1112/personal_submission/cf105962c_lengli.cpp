#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j] - '0';
        }
    }

    int ans = 0;
    vector<int> cnt(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j]) {
                cnt[j]++;
                ans = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int v = 0, w = 0;
            for (int k = 0; k < n; ++k) {
                if (grid[i][k] && grid[j][k]) {
                    v++;
                    w = max(w, cnt[k]);
                }
            }
            ans = max(ans, min(v, w));
        }
    }

    cout << ans << "\n";
    return 0;
}
