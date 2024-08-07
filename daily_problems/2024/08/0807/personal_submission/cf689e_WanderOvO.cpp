/*
如果所有线段覆盖的区域并不多，那么可以枚举覆盖的点，看有多少条线段覆盖了这个点
假设有 cnt 条线段覆盖了这个点，则 C(cnt, k) 就是这个点的贡献
本题覆盖的范围很大，但是线段数不多
可以离散化成一段一段的区间，统计每段区间被覆盖的次数，用类似的做法做
*/

int T;
LL n, k, fact[N], invfact[N];

void solve1() {
    cin >> n >> k;
    fact[0] = 1;
    invfact[0] = 1;
    int mod = MOD1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
        invfact[i] = qpow(fact[i], mod - 2, mod);
    }
    map<LL, LL> diff;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }
    LL last = -INFLL;
    LL res = 0, cnt = 0;
    for (auto &it : diff) {
        if (cnt >= k) {
            LL len = it.x - last;
            LL combine_cnt = (fact[cnt] * invfact[k] % mod) * invfact[cnt - k] % mod;
            res += len * combine_cnt % mod;
            res %= mod;
        }
        last = it.x;
        cnt += it.y;
    }
    cout << res << "\n";
}           
