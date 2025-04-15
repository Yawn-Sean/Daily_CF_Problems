/*
相当于有 m 个具有 n 个点的完全图，注意两个方向的边的边权不同
每个图可以自己跑一遍 floyd 求全源最短路
由于是完全图，所以 s 走到 t 至多经过 n - 1 条边，当然也至多只需要乘坐 n - 1 种不同的车，也就是换乘 n - 2 次
因此只关心 58 以内的 k
因此总共可能有 60 * 60 * 58 = 2e5 种不同的询问，实际上只会询问 1e5 次
完全可以先预处理出来所有的答案，然后直接回答
res[i][j][cnt]: 从 i 走到 j，至多换 cnt 次车，最短路是多少
res[i][j][cnt] = res[i][j][cnt - 1]
枚举最后一次换车的位置 pos，则有 res[i][j][cnt] = min(res[i][pos][cnt - 1] + res[pos][j][0])
res[i][j][0] 就是所有的 floyd 算出来之后取 min
*/

int n, m, r;
int w[N][N][N], d[N][N][N], res[N][N][N];

void floyd(int w[][N], int d[][N]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = w[i][j];
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void meibao() {
    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> w[i][j][k];
            }
        }
    }

    for (int k = 1; k <= m; k++) {
        floyd(w[k], d[k]);
    }

    memset(res, 0x3f, sizeof res);

    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                res[0][i][j] = min(res[0][i][j], d[k][i][j]);
            }
        }
    }

    for (int k = 1; k < N; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                res[k][i][j] = res[k - 1][i][j];
                for (int pos = 1; pos <= n; pos++) {
                    res[k][i][j] = min(res[k][i][j], res[k - 1][i][pos] + res[0][pos][j]);
                }
            }
        }
    }

    while (r--) {
        int s, t, k;
        cin >> s >> t >> k;
        k = min(k, N - 1);
        cout << res[k][s][t] << "\n";
    }
}   
