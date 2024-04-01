/*
没有奇数元环的图是二分图
集合中有 a 和 b
考虑 lcm(a, b) / a + lcm(a, b) / b，假如是奇数，则不行
需要 lcm(a, b) / a 和 lcm(a, b) / b 一奇数一偶数
lcm(a, b) / a = b / gcd(a, b)
lcm(a, b) / b = a / gcd(a, b)
a 单独的素因子中没有 2，b 单独的素因子中有 2，或者恰好反过来
枚举 (a, b) 对，求 gcd，分别除去之后不能加起来是奇数
如果是奇数，则至少删除其中一个
把满足 (a / gcd(a, b), b / gcd(a, b)) 奇偶性不同的 (a, b) 连边
然后看删除最少的点使得剩下的点都是孤立点

羊：gcd(a / gcd(a, b), b / gcd(a, b)) = 1
我们希望这两个东西都是奇数（因为都是偶数说明 2 没约干净）
其实就是希望 a 和 b 的素因子 2 的次数相同
我们统计每个数的素因子 2 的次数，然后按照次数统计个数，然后把最大的那个留下来即可
*/

int T;
LL n, b[N];
map<LL, vector<LL>> group;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        int cnt = 0;
        LL val = b[i];
        while (b[i] % 2 == 0) {
            cnt++;
            b[i] /= 2;
        }
        if (group.count(cnt)) {
            group[cnt].pb(val);
        } else {
            vector<LL> v;
            v.pb(val);
            group[cnt] = v;
        }
    }
    
    LL mxcnt = 0, f = 0;
    for (auto &it : group) {
        if (it.y.size() > mxcnt) {
            mxcnt = it.y.size();
            f = it.x;
        }
    }
    LL res = n - mxcnt;
    cout << res << "\n";
    for (auto &it : group) {
        if (it.x == f) continue;
        for (auto &val : it.y) {
            cout << val << " ";
        }
    }
}                