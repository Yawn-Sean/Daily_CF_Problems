/*
gcd(a, b) == x && lcm(a, b) == y
gcd(a / x, b / x) == 1, a, b 能整除 x
lcm(a / x, b / x) == a * b / x / x = y / x
其实就是看两个互素的数，lcm = y / x
x 需要能整除 y，否则一定是 0
x == y，则只有 a == b 才行
求 [1, n] 之间有多少这样的数对，只需要限制 a, b <= n / x，求 gcd(a, b) == 1, lcm(a, b) == y / x 的数对即可
既然 gcd(a, b) == 1，故 lcm(a, b) = a * b = y / x
对 y / x 进行素因数分解
每种素因子只能给 a 和 b 其中之一，这两个数都不能超过 n / x
素因子种类数不会很多，可以暴搜看 a 和 b 是多少
*/

int T;
LL l, r, x, y;
vector<LL> factors;
LL res = 0;

void dfs(int u, LL val1, LL val2, LL mn, LL mx) {
    if (u == factors.size()) {
        if (val1 <= mx && val2 <= mx && val1 >= mn && val2 >= mn) {
            res++;
        }
        return;
    }

    dfs(u + 1, val1 * factors[u], val2, mn, mx);
    dfs(u + 1, val1, val2 * factors[u], mn, mx);
}

LL calc() {
    if (y % x != 0) {
        return 0;
    }
    if (x == y) {
        if (x <= r && x >= l) {
            return 1;
        }
        return 0;
    }

    LL val = y / x, mx = r / x, mn = (l + x - 1) / x;
    LL rt = sqrt(val);
    factors.clear();
    for (int i = 2; i <= rt; i++) {
        if (val % i == 0) {
            LL v = 1;
            while (val % i == 0) {
                val /= i;
                v *= i;
            }
            factors.pb(v);
        }
    }
    if (val > 1) {
        factors.pb(val);
    }
    res = 0;
    dfs(0, 1, 1, mn, mx);
    return res;
}

void solve1() {
    cin >> l >> r >> x >> y;
    cout << calc() << "\n";
}                                                                                                                  