/*
数组 a 是非负的
b[i + 1] = b[i] - a[i] + a[i + k]
b[i + 1] - b[i] = a[i + k] - a[i]
b[1] = a[1] + ... + a[k]
又好像是熟悉的隔板法
如果前 k - 1 个数确定了，则后边的就都确定了，不考虑正负的话
我们根据 b[i + 1] - b[i] = a[i + k] - a[i]，能建出来一个图的样子
这个图有若干条链，类似 i, i + k, i + 2 * k, .... 
我们要保证这条链中每个元素都 >= 0，所以要求一个类似前缀和的东西，看前缀和里的最小值
即，用 a[i] 表示后边所有的 a[i + cnt * k]，即 a[i + cnt * k] = a[i] + val，求最小的 val
则 a[i] >= max(-val, 0)
这样，我们就知道了所有的 a[1]...a[k] 的下确界，每个 a[i] 满足这个条件一定有解的
接着，就是用隔板法，求 a[i] >= bound[i] 且 a[1] + ... + a[k] = b[1] 的解的个数了
我们先把所有的 bound[i] 都给减掉，就是 c[1] + ... + c[k] = val 的非负整数解个数了
再都加上 1，就是正整数解个数了，可以直接隔板法
这个组合数直接暴力乘起来就好了
*/

const int mod = 998244353;
LL n, k, b[N], bound[N];

LL qpow(LL a, LL b, LL mod) {
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

LL C(LL n, LL m) {
    LL res = 1;
    for (LL i = n - m + 1; i <= n; i++) {
        res *= i;
        res %= mod;
    }
    LL t = 1;
    for (int i = 1; i <= m; i++) {
        t *= i;
        t %= mod;
    }
    return res * qpow(t, mod - 2, mod) % mod;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n - k + 1; i++) {
        cin >> b[i];
    }
    
    for (int i = 1; i <= k; i++) {
        LL mn = 0, cur = 0;
        for (int j = i; j + k <= n; j += k) {
            // a[j + k] - a[j] = b[j + 1] - b[j]
            cur += b[j + 1] - b[j];
            mn = min(mn, cur);
        }
        
        bound[i] = max(0LL, -mn);
    }
    
    LL total = b[1];
    for (int i = 1; i <= k; i++) {
        total -= bound[i];
    }
    
    if (total < 0) {
        cout << "0\n";
        return;
    }
    
    total += k;
    cout << C(total - 1, k - 1) << "\n";
}
