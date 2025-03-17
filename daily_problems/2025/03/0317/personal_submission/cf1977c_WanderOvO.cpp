/*
a 中只要不存在一个数是所有数的倍数，则可以把整个序列选上
a 中假如任意两个数都有倍数关系，则一个都选不了
假如 x 是 y 的倍数，则选了 x 之后再选 y 不会影响答案，可以凭空增加长度
顺序无所谓，先排个序
lcm 一定 >= 选的最大的数
lcm 其实就是对每种素因子的次数取 max

2 42 7 3 6 7 7 1 6
1 2 3 6 6 7 7 7 42

3 2 10 20 60 1
1 2 3 10 20 60
假如所有数的 lcm = 最大值，则先考虑怎样能让 lcm 不是最大值
首先把最大值去掉，然后只要使得某一个素因子的次数不满足要求即可

如果考虑所有素因子次数组合，需要考虑多少种情况？
2 至多 32 次，3 至多 20 次，4 至多 16 次，5 至多 13 次，7 至多 11 次，11 至多 10 次
13 至多 8 次...好像有点多，没法暴搜后验证
每个数至多有 9 种不同的素因子，所以至多有 9000 个不同的素因子
再仔细估计一下，发现也就不到 4000

假如整个数列不能是答案，则说明 a 的最大值中的每种素因子的次数都是整个数列中最大的
这个时候，我们随便选一个子序列，其 lcm 一定能整除 a 中的最大值
所以我们枚举 a 的最大值的所有约数，假如没在数列中出现过，则可以验证是否能满足
*/

int T;
LL a[N], n;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

void solve1() {
    cin >> n;
    
    LL all_lcm = 1;
    set<int> vals;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vals.insert(a[i]);
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        all_lcm = lcm(all_lcm, a[i]);
        if (all_lcm > a[n]) {
            cout << n << "\n";
            return;
        }
    }

    LL rt = sqrt(all_lcm);
    int res = 0;
    for (int i = 1; i <= rt; i++) {
        if (all_lcm % i == 0) {
            if (!vals.count(i)) {
                int ans = 0;
                int val = i;
                LL cur_lcm = 1;
                for (int j = 1; j <= n; j++) {
                    if (val % a[j] == 0) {
                        cur_lcm = lcm(cur_lcm, a[j]);
                        ans++;
                    }
                }
                if (cur_lcm == val) {
                    res = max(res, ans);
                }
            }
            if (!vals.count(all_lcm / i)) {
                int ans = 0;
                int val = all_lcm / i;
                LL cur_lcm = 1;
                for (int j = 1; j <= n; j++) {
                    if (val % a[j] == 0) {
                        cur_lcm = lcm(cur_lcm, a[j]);
                        ans++;
                    }
                }
                if (cur_lcm == val) {
                    res = max(res, ans);
                }
            }
        }
    }
    if (res == 1) {
        res = 0;
    }
    cout << res << "\n";
}       
