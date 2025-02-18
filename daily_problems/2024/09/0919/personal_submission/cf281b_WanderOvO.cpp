/*
分母 b <= n，分子 a > 0
不妨先约分一下，如果 n >= y，则直接输出约分后的 x / y
如果 n < y，枚举分母 b，令 a / b = x / y，得到 a = x * b / y，用浮点数
然后暴力看 a - 2, a - 1, a, a + 1, a + 2，找一个最小的
*/

int T;
LL x, y, n;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve1() {
    cin >> x >> y >> n;
    LL g = gcd(x, y);
    x /= g;
    y /= g;
    if (n >= y) {
        cout << x << "/" << y << "\n";
        return;
    }
    double min_d = INFLL;
    LL res_a, res_b;
    for (LL b = 1; b <= n; b++) {
        LL a = (x * b * 1.0) / y;
        vector<LL> candidates;
        candidates.pb(a);
        if (a - 1 >= 0) {
            candidates.pb(a - 1);
        }
        if (a - 2 >= 0) {
            candidates.pb(a - 2);
        }
        candidates.pb(a + 1);
        candidates.pb(a + 2);
        for (auto candidate : candidates) {
            double ch = fabs((1.0 * x) / y - (1.0 * candidate) / b);
            if (fabs(ch - min_d) < eps) {
                if (b < res_b) {
                    res_b = b;
                    res_a = candidate;
                } else if (b == res_b) {
                    if (candidate < res_a) {
                        res_a = candidate;
                    }
                }
            } else if (ch < min_d) {
                min_d = ch;
                res_a = candidate;
                res_b = b;
            } 
        }
    }
    cout << res_a << "/" << res_b << "\n";
}          
