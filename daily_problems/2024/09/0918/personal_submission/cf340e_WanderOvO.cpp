/*
2 3 1 5 4
-1 3 -1 5 4
如果最开始就有 a[i] = i 的数了，直接不用算了
如果没有，考虑还没填的数字 val
val 可以分成两类：
- a[val] = -1，则 val 还不能随便填
- a[val] != -1，则 val 已经可以随便填了
假设有 not_free_cnt 个数字还存在禁止填的地方，free_cnt 个数字可以随便填
m = not_free_cnt + free_cnt
第一步是求从 m 个位置中选 not_free_cnt 个位置放数，使得满足题意的方案数
容斥，枚举至少有 i 个数放在了不动点位置，1 <= i <= not_free_cnt
C(not_free_cnt, i) * (m - i)!
总方案数 m!
*/

int T;
LL n, a[N];
vector<LL> fact(N, 0), invfact(N, 0);

LL C(LL a, LL b, LL MOD) {
    LL res = (fact[a] * invfact[b] % MOD) * invfact[a - b] % MOD;
    return res;
}

LL qpow(LL a, LL b, LL MOD) {
    LL res = 1, base = a % MOD;
    while (b) {
        if (b & 1) {
            res = res * base % MOD;
        }
        base = base * base % MOD;
        b >>= 1;
    }
    return res % MOD;
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    LL free_cnt = 0, not_free_cnt = 0;
    set<int> not_appear;
    for (int i = 1; i <= n; i++) {
        not_appear.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) {
            cout << "0\n";
            return;
        }
        if (a[i] != -1) {
            not_appear.erase(a[i]);
        }
    }
    for (auto val : not_appear) {
        if (a[val] == -1) {
            not_free_cnt++;
        } else {
            free_cnt++;
        }
    }
    int mod = MOD1;
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
        invfact[i] = qpow(fact[i], mod - 2, mod);
    }
    LL res = 0;
    LL m = free_cnt + not_free_cnt;
    for (int i = 1; i <= not_free_cnt; i++) {
        res += (i % 2 ? 1 : -1) * C(not_free_cnt, i, mod) * fact[m - i] % mod;
        res %= mod;
    }
    cout << ((fact[m] - res) % mod + mod) % mod << "\n";
}        
