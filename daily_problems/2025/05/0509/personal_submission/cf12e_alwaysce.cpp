#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            ans[i][j] = (i + j) % (n - 1) + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int cur = ans[i][i];
        ans[n - 1][i] = cur;
        ans[i][n - 1] = cur;
        ans[i][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
