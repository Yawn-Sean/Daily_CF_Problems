/*
d > 0，往两头加
d < 0，往中间加
*/

LL n, m;

void meibao() {
    cin >> n >> m;
    LL sum = 0;
    LL tot_cnt1 = n * (n - 1) / 2;
    LL tot_cnt2 = 0;
    if (n % 2 == 0) {
        LL half = n / 2;
        tot_cnt2 = half * (half - 1) + half;
    } else {
        LL half = n / 2;
        tot_cnt2 = (1 + half) * half;
    }
    for (int i = 1; i <= m; i++) {
        LL x, d;
        cin >> x >> d;
        if (d > 0) {
            sum += n * x + tot_cnt1 * d;
        } else {
            sum += n * x + tot_cnt2 * d;
        }
    }
    double res = sum;
    res /= n;
    cout << setprecision(18) << res << "\n";
}  
