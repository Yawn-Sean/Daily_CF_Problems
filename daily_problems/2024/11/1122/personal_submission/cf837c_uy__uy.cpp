#include<bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //freopen("input.in", "r", stdin);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> pre(n + 1, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            pre[i + 1][j] = pre[i][j] + a[i][j];
        }
    }
    int ans = 0;
    int ex = 0;
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        int e = 0;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == 1) {
                int x = min(k, n - j);
                if (pre[j + x][i] - pre[j][i] > cnt) {
                    cnt = pre[j + x][i] - pre[j][i];
                    e = pre[j][i];
                }

            }
        }
        ans += cnt;
        ex += e;
    }
    cout << ans << " " << ex << "\n";
    return 0;
}
