/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-19 16:05 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> mp(n);
    for (int i = 0; i < n; i ++) cin >> mp[i];
    vector cnt(n + 1, vector (m + 1, 0));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (mp[i][j] == '1') cnt[i + 1][j + 1] = 1;
            cnt[i + 1][j + 1] += cnt[i][j + 1] + cnt[i + 1][j] - cnt[i][j];
        }
    }
    vector sum(n + 1, vector (m + 1, vector(n + 1, vector (m + 1, 0))));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            for (int k = i; k <= n; k ++) {
                for (int l = j; l <= m; l ++) {
                    if (cnt[k][l] + cnt[i - 1][j - 1] - cnt[k][j - 1] - cnt[i - 1][l] == 0) {
                        sum[n - i + 1][m - j + 1][k][l] = 1;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            for (int k = 1; k <= n; k ++) {
                for (int l = 1; l <= m; l ++) {
                    sum[i][j][k][l] += sum[i - 1][j][k][l];
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            for (int k = 1; k <= n; k ++) {
                for (int l = 1; l <= m; l ++) {
                    sum[i][j][k][l] += sum[i][j - 1][k][l];
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            for (int k = 1; k <= n; k ++) {
                for (int l = 1; l <= m; l ++) {
                    sum[i][j][k][l] += sum[i][j][k - 1][l];
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            for (int k = 1; k <= n; k ++) {
                for (int l = 1; l <= m; l ++) {
                    sum[i][j][k][l] += sum[i][j][k][l - 1];
                }
            }
        }
    }
    while (q --) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[n - x1 + 1][m - y1 + 1][x2][y2] << "\n";
    }
    return 0;
}

#endif

/*

*/
