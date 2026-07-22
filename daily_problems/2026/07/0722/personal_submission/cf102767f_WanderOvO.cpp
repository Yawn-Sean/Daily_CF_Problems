/*
x 是素数，说明了什么？
最大值能否先求出来？
x 并不大，范围是 [2, 97]
余数在 [0, x - 1] 范围内
注意到 1 <= a[i] < x 也成立
这说明了，一个区间里的 a[i] 相乘，肯定凑不出素因子 x，所以余数肯定不会是 0
我们能否检验，最大的余数能否是 ans
也就是说，是否存在 l <= r，使得 a[l] * ... * a[r] % x = ans
s[r] 设为前缀乘积
s[r] * inv(s[l - 1]) % x = ans
s[r] * inv(s[l - 1]) = ans + k * x
s[r] * inv(s[l - 1]) - x * k = ans
要看这个关于 inv(s[l - 1]) 和 k 的方程有没有整数解
gcd(s[r], -x) | ans，则有整数解
接下来就是求 inv(s[l - 1]) 的最小正整数解，看这个东西对应的 l - 1 是多少
如果没有，就增大 inv(s[l - 1])
inv(s[l - 1]) 不会超过 x，所以应该不需要枚举几个数

a * (xx + d1) + b * (xx - d2) = ans
ad1 = bd2
d2 = ad1 / b
a * d1 = lcm(a, b)
d1 = lcm(a, b) / a
d1 = b / gcd(a, b)
*/

const int N = 2e5 + 10;

int n, a[N], s[N], x, inv_s[N];

int qpow(int a, int b, int mod) {
    int res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = res * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return res % mod;
}

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int res = exgcd(b, a % b, x, y);

    int t = x;
    x = y;
    y = t - a / b * y;
    return res;
}

void solve() {
    cin >> n >> x;
    s[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] * a[i] % x;
        inv_s[i] = qpow(s[i], x - 2, x);
    }

    int max_ans = 0, min_len = n + 1;
    for (int ans = x - 1; ans >= 0; ans--) {
        map<int, int> pos;
        pos[1] = 0;
        for (int r = 1; r <= n; r++) {
            int xx, yy;
            int a = s[r], b = -x;
            int g = exgcd(a, b, xx, yy);
            if (g != 0 && ans % g == 0) {
                xx *= ans / g;
                yy *= ans / g;
                
                int d1 = abs(b / g);
                xx = (xx % d1 + d1) % d1;
                for (int val = xx; val < x; val += d1) {
                    if (pos.count(val)) {
                        max_ans = ans;
                        min_len = min(min_len, r - pos[val]);
                    }
                }
            }
            pos[inv_s[r]] = r;
        }
        if (max_ans > 0) {
            break;
        }
    }

    cout << max_ans << " " << min_len << "\n";
}
