/*
问题转化，相当于开始给定了 n 个点 (h[i], w[i])，每个点的权值是 h[i] * w[i]
每次询问给定一个矩形，需要求完全落在矩形里面的点的权值和
*/
 
LL s[M][M], n, q;
 
void meibao() {
    cin >> n >> q;
    memset(s, 0, sizeof s);
    for (int i = 1; i <= n; i++) {
        LL h, w;
        cin >> h >> w;
        s[h][w] += h * w;
    }
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < M; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    while (q--) {
        LL hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        if (hs + 2 > hb || ws + 2 > wb) {
            cout << "0\n";
        } else {
            hs++;
            hb--;
            ws++;
            wb--;
            cout << s[hb][wb] - s[hb][ws - 1] - s[hs - 1][wb] + s[hs - 1][ws - 1] << "\n";
        }
    }
}
