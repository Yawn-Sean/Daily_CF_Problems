/*
sum(a[i] ^ x) = k
我们似乎关心每个数位为 0 和 1 的次数，统计一下
枚举 x，x 为 0 的位，则把这位的 1 的次数贡献进来，否则看 0 的次数
但是这个题范围非常巨大，如何处理？
a[i] <= 1e5，所以 x 很大的时候高位总贡献就是 x 高位的 n 倍
x 没有限制
我们考虑高位全 0 和高位全 1，这个应该能把低位所有情况再循环若干遍
只需要暴力看 x <= (1 << 17) 的情况
高位 x 的每个 1，都会贡献 n * 2^i
s, s + cnt * n * (1 << 17)
*/ 

void solve() {
    LL n, l, r;
    cin >> n >> l >> r;
    vector<LL> a(n + 1, 0);
    vector<LL> cnt(20, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < 17; j++) {
            if ((a[i] >> j) & 1) {
                cnt[j]++;
            }
        }
    }

    set<LL> small_sum;
    for (int x = 0; x < (1 << 17); x++) {
        LL sum = 0;
        for (int i = 0; i < 17; i++) {
            if ((x >> i) & 1) {
                sum += (n - cnt[i]) * (1LL << i);
            } else {
                sum += cnt[i] * (1LL << i);
            }
        }
        if (sum <= r) {
            small_sum.insert(sum);
        }
    }

    auto check1 = [&] (LL x, LL sum) -> bool {
        return sum + n * x * (1LL << 17) >= l;
    };

    auto check2 = [&] (LL x, LL sum) -> bool {
        return sum + n * x * (1LL << 17) <= r;
    };

    auto calc = [&] (LL sum) -> LL {
        LL res = 0;

        LL st = -1, ed = -1;
        LL mx = 1e18 / (1LL << 17);
        LL lo = 0, hi = mx / n, mid;
        while (lo + 1 < hi) {
            mid = (lo + hi) / 2;
            // mid 是否超过下限
            if (check1(mid, sum)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        if (check1(lo, sum)) {
            st = lo;
        } else if (check1(hi, sum)) {
            st = hi;
        } else {
            return 0;
        }

        lo = 0;
        hi = mx / n;
        while (lo + 1 < hi) {
            mid = (lo + hi) / 2;
            // mid 是否低于上限
            if (check2(mid, sum)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        if (check2(hi, sum)) {
            ed = hi;
        } else if (check2(lo, sum)) {
            ed = lo;
        } else {
            return 0;
        }

        res = ed - st + 1;
        return res;
    };

    LL ans = 0;
    for (auto sum : small_sum) {
        // cout << "sum: " << sum << "\n";
        ans += calc(sum);
    }
    cout << ans << "\n";
}
