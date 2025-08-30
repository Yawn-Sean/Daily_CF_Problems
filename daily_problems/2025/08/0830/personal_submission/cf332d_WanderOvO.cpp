/*
考虑统计每条边贡献了多少次，加权加起来求平均
考虑某条边 (u, v, w)，其可以贡献，说明 u 或者 v 中至少有一个能和一个 k 集合邻接
u 和 v 也可能都能和 k 集合邻接
不妨先考虑 u 的情况，看 u 有多少条邻边，假设有 cnt 条，如果 cnt >= k，说明 u 确实是一个很好的点
统计 u 作为关键点时，(u, v, w) 贡献了多少次，即需要在剩下 cnt - 1 条边里再选 k - 1 条边
v 作为关键点也是类似的
最后的结果要向下取整，很奇妙
数似乎很大呀，真的能存下吗？
*/

LL w[M][M], n, k, cnt[M], c[M][M];

void meibao() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            w[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> w[i][j];
            w[j][i] = w[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (w[i][j] != -1) {
                cnt[i]++;
            }
        }
    }

    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }

    LL res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (w[i][j] != -1) {
                int u = i;
                if (cnt[u] >= k) {
                    res += w[i][j] * c[cnt[u] - 1][k - 1];
                }
            }
        }
    }

    res /= c[n][k];
    cout << res << "\n";
}
