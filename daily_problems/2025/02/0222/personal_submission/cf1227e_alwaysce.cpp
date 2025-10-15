#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        每次烧掉的都是一个方块
        方块不能超出边界

        二分答案T
        然后考虑X扩展
    */
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto&s: grid) { cin >> s; }

    // 二维前缀和 X
    vector<vector<int>> pre(n + 1, vector<int>(m + 1)), ngrid(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                pre[i+1][j+1] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] += pre[i][j-1];
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            pre[i][j] += pre[i-1][j];
        }
    }

    // (x,y)为中心 t为半径
    auto check = [&](int x, int y, int t) {
        int tot = pre[x + t + 1][y + t + 1] - pre[x + t + 1][y - t] - pre[x - t][y + t + 1] + pre[x - t][y - t];
        return tot == (2 * t + 1) * (2 * t + 1);
    };

    int left = 0, right = min(n, m) / 2 + 1;
    int ans = 0;
    while (left < right) {
        int mid = (left + right) / 2;
        for (int i = mid; i < n - mid; i++) {
            for (int j = mid; j < m - mid; j++) {
                if (check(i, j, mid)) {
                    // 将区域更新到ngrid上
                    ngrid[i - mid][j - mid] += 1;
                    ngrid[i - mid][j + mid + 1] -= 1;
                    ngrid[i + mid + 1][j - mid] -= 1;
                    ngrid[i + mid + 1][j + mid + 1] += 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                ngrid[i][j] += ngrid[i][j-1];
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                ngrid[i][j] += ngrid[i-1][j];
            }
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ok &= ((grid[i][j] == 'X') == (ngrid[i][j] > 0));
                ngrid[i][j] = 0; // reset
            }
        }

        if (ok) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid;
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= ans && i < n - ans && j >= ans && j < m - ans) {
                if (check(i, j, ans)) {
                    cout << 'X';
                } else {
                    cout << '.';
                }
            } else {
                cout <<  '.';
            }
        }
        cout << '\n';
    }


    return 0;
}
