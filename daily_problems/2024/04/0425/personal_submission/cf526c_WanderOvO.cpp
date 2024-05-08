LL c, hr, hb, wr, wb;

void solve1() {
    cin >> c >> hr >> hb >> wr >> wb;
    LL res = 0;
    // 将 r 换成 b，枚举最后剩余 r 的个数
    for (int i = 0; i <= N; i++) {
        if (wr * i > c) break;
        res = max(res, i * hr + (c - wr * i) / wb * hb);
    }
    // 将 b 换成 r，枚举最后剩余 b 的个数
    for (int i = 0; i <= N; i++) {
        if (wb * i > c) break;
        res = max(res, i * hb + (c - wb * i) / wr * hr);
    }
    cout << res << "\n";
}      