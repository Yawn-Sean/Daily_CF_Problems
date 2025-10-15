/*
每个位置应该有 k / d 场比赛，类似均分纸牌，但是不是环形的
第一个位置只能从右边得到，或者给出去
注意到可以直接从左向右贪心，多了就给出去，少了就从左边拿
不用担心减成负数的问题，因为操作顺序可以调
*/
 
LL n, a[N];
 
void meibao() {
    cin >> n;
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    LL avg = sum / n;
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > avg) {
            res += a[i] - avg;
            a[i + 1] += a[i] - avg;
            a[i] = avg;
        } else {
            res += avg - a[i];
            a[i + 1] -= avg - a[i];
            a[i] = avg;
        }
    }
    cout << res << "\n";
}
 
