/*
走到正上面的：2r
走到左上和右上的：(2 + sqrt(2))r
走到其他的：假设横向差 cnt * r，其中 cnt >= 4 且 cnt 为偶数，则需要走 (cnt - 2) * r + 2 * sqrt(2) * r
所有的都有一个正上方的，所以先有一个 2 * m * r 打底
左上和右上，两头的各有一个，中间的 m - 2 个都有 2 个，所以是 (2 * m - 2) * (2 + sqrt(2)) * r
其他的，枚举 cnt = 4, 6, ..., 2 * m - 2，对于每个 cnt，分别有多少对呢？
2 * (m - cnt) + cnt = 2 * m - cnt 对
*/

LL m;
double r;

void meibao() {
    cin >> m >> r;
    double res = 0;
    res += 2 * m * r;
    res += (2 * m - 2) * (2 + sqrt(2)) * r;
    for (LL cnt = 4; cnt <= 2 * m - 2; cnt += 2) {
        res += (2 * m - cnt) * ((cnt - 2) * r + 2 * sqrt(2) * r);
    }
    res /= m;
    res /= m;
    cout << setprecision(15) << res << "\n";
}
