/*
sum(c[i][j] * d^2) = sum(c[i][j] * dx^2 + c[i][j] * dy^2)
= sum(c[i][j] * (x0 - x[i])^2 + c[i][j] * (y0 - y[j])^2)
x[i] = 4 * i - 2, y[j] = 4 * j - 2
枚举格点 (r, c)，x0 = 4 * r, y0 = 4 * c
sum(c[i][j] * (x0 - x[i])^2 + c[i][j] * (y0 - y[j])^2)
= sum(c[i][j] * (x0^2 + y0^2 + x[i]^2 + y[j]^2 - 2 * x0 * x[i] - 2 * y0 * y[j]))
= sum(c[i][j] * (x[i]^2 + y[j]^2)) + (x0^2 + y0^2) * sum(c[i][j]) 
- 2 * x0 * sum(c[i][j] * x[i]) - 2 * y0 * sum(c[i][j] * y[j])
第一部分是定值，后边三个部分分别需要预处理 3 个不同的和
然后枚举 x0, y0 即可
*/

LL n, m, c[M][M], x[M], y[M];

void meibao() {
    cin >> n >> m;
    LL s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    for (int i = 1; i < M; i++) {
        x[i] = 4 * i - 2;
        y[i] = 4 * i - 2;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            s1 += c[i][j] * (x[i] * x[i] + y[j] * y[j]);
            s2 += c[i][j];
            s3 += c[i][j] * x[i];
            s4 += c[i][j] * y[j];
        }
    }
    LL res = INFLL, resx = 0, resy = 0;
    for (int r = 0; r <= n; r++) {
        for (int c = 0; c <= m; c++) {
            LL x0 = 4 * r, y0 = 4 * c;
            LL ans = s1 + s2 * (x0 * x0 + y0 * y0) - 2 * x0 * s3 - 2 * y0 * s4;
            if (ans < res) {
                res = ans;
                resx = r;
                resy = c;
            }
        }
    }
    cout << res << "\n" << resx << " " << resy << "\n";
}
