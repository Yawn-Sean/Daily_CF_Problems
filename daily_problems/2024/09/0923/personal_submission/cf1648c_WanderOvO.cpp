/*
考虑枚举从哪个字符开始不一样，s[i] < t[i]
需要预处理 s 中所有字符的出现次数
先把 1-(i - 1) 用到的字符减掉，然后选一个严格小的放到第 i 个位置
对于后面的，需要求一个多重集的排列数
假设还剩下 tot 个字符没用到，每个字符的数量是 cnt[i]
排列数是 tot! / prod(cnt[i]!)
prod(cnt[i]!) 可以预处理出来，每次 i++ 后用逆元处理掉
每枚举到一个 i，需要把所有 < t[i] 的 s 中剩下的字符都枚举一遍
字符种类数很多时枚举就爆了，最坏 O(n^2)
我们对思路稍作修改
考虑从第 i 个字符开始不一样，我们先假设没有重复字符，则后面的我们分步去排列
首先，选一个 < t[i] 的字符，假设总共有 x 个，然后剩下的 n - i 个数全排列
则方案数是 x * (n - i)! 种
考虑顺序，就是把每个数的顺序给去掉，直接把阶乘除掉即可
*/

LL n, m;
LL s[N], t[N], fact[N], invfact[N], cnt[N];
BIT bit;

void solve1() {
    cin >> n >> m;
    bit.init(N - 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        bit.add(s[i], 1);
        cnt[s[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i];
    }

    fact[0] = 1;
    invfact[0] = 1;
    int mod = MOD2;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
        invfact[i] = qpow(fact[i], mod - 2, mod);
    }

    LL prod_fact = 1;
    LL res = 0;
    for (int i = 1; i < N; i++) {
        prod_fact *= fact[cnt[i]];
        prod_fact %= mod;
    }
    for (int i = 1; i <= min(n, m); i++) {
        if (i == min(n, m)) {
            if (n < m) {
                if (cnt[t[i]] > 0) {
                    res++;
                }
            }
        }
        LL less_cnt = bit.query(t[i] - 1);
        LL contrib = less_cnt * fact[n - i] % mod;
        contrib *= qpow(prod_fact, mod - 2, mod);
        contrib %= mod;
        res += contrib;
        res %= mod;
        if (cnt[t[i]] > 0) {
            cnt[t[i]]--;
            bit.add(t[i], -1);
            prod_fact *= qpow(cnt[t[i]] + 1, mod - 2, mod);
            prod_fact %= mod;
        } else {
            break;
        }
    }
    cout << res << "\n";
}                                                                                                                  
