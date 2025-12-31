/*
题目对 sum of k(1e12) 和 sum of max(a[i]) (1e6) 有限制，何意味
我们考虑 a[i] 求和 + k，会发现不管怎么操作，最后总和是一定的
而这个总和，应该是最大公约数 g 的若干倍
所以 g 一定是 sum(a[i]) + k 的约数
g 可能的数量可能有 1e4 左右
对于一个 g，我们怎么检查其符合题意？
还是用暴力枚举加补齐的话，似乎时间上吃不消
但是这个题给了 3 秒啊，未必没有机会
写了一下，T 了，我们可能要用更快速的办法
我们刚才其实发现了一个事情
最后的答案是不会超过 k / n + 1e6 的
因为最开始最大的就是 1e6，k / n 是每个数平均被加的次数
如果最大的数被加更多，答案也不会变大了

羊的提示：
如果 g 很大，超过了 1e6，那么每个数都得变成 g，这个是不用循环去算的
如果 g <= 1e6，则是可以分段去算的，因为 0-g 都是变成 g，g + 1 到 2g 都是变成 2g...
*/ 

void solve() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n + 1, 0);
    LL s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    s += k;
    LL root = sqrt(s);
    vector<LL> factors;
    for (int i = 1; i <= root; i++) {
        if (s % i == 0) {
            factors.push_back(i);
            if (s / i != i) {
                factors.push_back(s / i);
            }
        }
    }
    
    sort(factors.rbegin(), factors.rend());
    
    LL mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
    }
    vector<LL> cnt(mx + 1, 0);
    vector<LL> sum(mx + 1, 0);
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 1; i <= mx; i++) {
        sum[i] = sum[i - 1] + cnt[i] * i;
        cnt[i] += cnt[i - 1];
    }

    for (auto g : factors) {
        LL left_cnt = k;
        if (g <= mx) {
            for (LL i = g; i <= 2 * mx; i += g) {
                LL j = i - g;
                LL c = cnt[min(i, mx)] - cnt[min(j, mx)];
                left_cnt -= c * i - (sum[min(i, mx)] - sum[min(j, mx)]);
                if (left_cnt < 0) {
                    break;
                }
            }
        } else {
            left_cnt -= n * g - (s - k);
        }
        if (left_cnt % g == 0 && left_cnt >= 0) {
            cout << g << "\n";
            return;
        }
    }
}
