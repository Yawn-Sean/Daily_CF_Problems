/*
感觉和上个题好像啊
相当于钦定了 ans = 1
s[r] * inv(s[l - 1]) % n = 1
s[r] * inv(s[l - 1]) = 1 + n * k
s[r] * inv(s[l - 1]) - n * k = 1
gcd(s[r], -n) | 1 才行
其实就是相当于，我们枚举 s[r]，要找到它的逆元 inv(s[r])
这里逆元还不一定存在，这会带来很大的麻烦

我们先让所有的 a[i] %= n
然后可能会有一些地方出现 0，我们用 0 把序列分成若干个非 0 段
如果左右端点跨段，肯定乘积 % n = 0 != 1，所以左右端点一定在同一段里面
对于同一段内，考虑求前缀积
但也不行，因为乘积有可能是 n 的倍数，仍然会导致逆元不存在

我们考虑分段，每段里不能有 gcd(a[i], n) > 1 的元素，否则一定不能有
然后每段内去做即可
*/ 

const int N = 2e5 + 10;

LL n, a[N], s[N], x, inv_s[N];

LL qpow(LL a, LL b, int mod) {
    LL res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = res * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return res % mod;
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
 
    LL res = exgcd(b, a % b, x, y);
 
    LL t = x;
    x = y;
    y = t - a / b * y;
    return res;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= n;
    }

    int min_len = n + 1;

    for (int i = 1; i <= n; ) {
        if (a[i] != 0 && __gcd(a[i], n) == 1) {
            int j = i;
            while (j <= n && a[j] != 0 && __gcd(a[j], n) == 1) {
                j++;
            }

            j--;

            s[0] = 1;
            inv_s[0] = 1;
            for (int k = i; k <= j; k++) {
                s[k - i + 1] = s[k - i] * a[k] % n;
                // s[k - i + 1] * inv(s[k - i + 1]) % n == 1
                // s[k - i + 1] * inv(s[k - i + 1]) - n * k == 1
                LL xx, yy;
                LL g = exgcd(s[k - i + 1], -n, xx, yy);
                xx *= 1 / g;
                yy *= 1 / g;
                xx = (xx % n + n) % n;
                inv_s[k - i + 1] = xx;
            }

            map<LL, int> pos;
            pos[1] = 0;
            for (int k = i; k <= j; k++) {
                int r = k - i + 1;
                if (pos.count(inv_s[r])) {
                    min_len = min(min_len, r - pos[inv_s[r]]);
                }
                pos[inv_s[r]] = r;
            }
            i = j + 1;
        } else {
            i++;
        }
    }

    if (min_len == n + 1) {
        min_len = 0;
    }
    cout << min_len << "\n";
}
