/*
某行被操作了多少次，至多被操作的次数就是这一行的最小值
可以先考虑行，求出每行的最小值，然后按行染色
行都处理完了，再处理列，这个时候要考虑染行带来的影响
另一种情况是先染列，再染行，同样做一遍
染色完，和 g 比较一下，看看是不是一样
选次数较小的那个方案
*/

int n, m, g[M][M], a[M][M];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    int res = INF;
    int res1 = 0, res2 = 0;
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n; i++) {
        int mn = 510;
        for (int j = 1; j <= m; j++) {
            mn = min(mn, g[i][j]);
        }
        res1 += mn;
        for (int j = 1; j <= m; j++) {
            a[i][j] = mn;
        }
    }

    for (int j = 1; j <= m; j++) {
        int mn = 510;
        for (int i = 1; i <= n; i++) {
            mn = min(mn, g[i][j] - a[i][j]);
        }
        res1 += mn;
        for (int i = 1; i <= n; i++) {
            a[i][j] += mn;
        }
    }

    bool same = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            same &= (a[i][j] == g[i][j]);
        }
    }
    if (!same) {
        res1 = INF;
    }

    memset(a, 0, sizeof a);
    for (int j = 1; j <= m; j++) {
        int mn = 510;
        for (int i = 1; i <= n; i++) {
            mn = min(mn, g[i][j]);
        }
        res2 += mn;
        for (int i = 1; i <= n; i++) {
            a[i][j] = mn;
        }
    }

    for (int i = 1; i <= n; i++) {
        int mn = 510;
        for (int j = 1; j <= m; j++) {
            mn = min(mn, g[i][j] - a[i][j]);
        }
        res2 += mn;
        for (int j = 1; j <= m; j++) {
            a[i][j] += mn;
        }
    }

    same = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            same &= (a[i][j] == g[i][j]);
        }
    }
    if (!same) {
        res2 = INF;
    }

    if (res1 == INF && res2 == INF) {
        cout << "-1\n";
    } else {
        memset(a, 0, sizeof a);
        if (res1 < res2) {
            cout << res1 << "\n";
            for (int i = 1; i <= n; i++) {
                int mn = 510;
                for (int j = 1; j <= m; j++) {
                    mn = min(mn, g[i][j]);
                }
                for (int j = 1; j <= mn; j++) {
                    cout << "row " << i << "\n";
                }
                for (int j = 1; j <= m; j++) {
                    a[i][j] = mn;
                }
            }

            for (int j = 1; j <= m; j++) {
                int mn = 510;
                for (int i = 1; i <= n; i++) {
                    mn = min(mn, g[i][j] - a[i][j]);
                }
                for (int i = 1; i <= mn; i++) {
                    cout << "col " << j << "\n";
                }
                for (int i = 1; i <= n; i++) {
                    a[i][j] += mn;
                }
            }
        } else {
            cout << res2 << "\n";
            for (int j = 1; j <= m; j++) {
                int mn = 510;
                for (int i = 1; i <= n; i++) {
                    mn = min(mn, g[i][j]);
                }
                for (int i = 1; i <= mn; i++) {
                    cout << "col " << j << "\n";
                }
                for (int i = 1; i <= n; i++) {
                    a[i][j] = mn;
                }
            }

            for (int i = 1; i <= n; i++) {
                int mn = 510;
                for (int j = 1; j <= m; j++) {
                    mn = min(mn, g[i][j] - a[i][j]);
                }
                for (int j = 1; j <= mn; j++) {
                    cout << "row " << i << "\n";
                }
                for (int j = 1; j <= m; j++) {
                    a[i][j] += mn;
                }
            }
        }
    }
}
