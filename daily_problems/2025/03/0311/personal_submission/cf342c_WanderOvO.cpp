/*
下面的长方体部分只可能是每层 2 个去排，只有最上面可能有不同的放法
下面排满了，能放 (h / r) * 2 个球
考虑上面怎么排，上面至少还剩下 r 的高度，所以放一个肯定可以
能放 2 个吗？这样需要增加 1 层，这需要下边至少还剩下 r / 2 的高度，否则放不下两个
能放 3 个吗？画图可知需要 h - h / r * r + r >= (sqrt(3) / 2 + 1) * r，即 h - h / r * r >= sqrt(3) / 2 * r
*/

LL h, r;

void meibao() {
    cin >> r >> h;
    LL res = h / r * 2;
    double left = h - h / r * r;
    if (left > sqrt(3) / 2 * r || fabs(left - sqrt(3) / 2 * r) < eps) {
        res += 3;
    } else if (left > r / 2.0 || fabs(left - r / 2.0) < eps) {
        res += 2;
    } else {
        res++;
    }
    cout << res << "\n";
}
