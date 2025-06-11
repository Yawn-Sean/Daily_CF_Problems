/*
给了 k，则为 1 的位可以有哪些二进制位就确定了
对于某个为 1 的二进制位，其至少在某个 a[i] & a[i + 1] 中也为 1
可以单独考虑某一位，然后把方案乘起来
- 假如 k 的某个二进制位为 0，则所有的 a[i] & a[i + 1] 都得是 0，所以不存在连续两个数的这个位同时为 1
- 假如 k 的某个二进制位为 1，则存在某个 a[i] & a[i + 1] 的这一位为 1，所以存在连续两个数的这个位同时为 1
这两个情况加起来正好是所有情况的方案数
怎么算这两个情况的数量？
对于第一种，我们可以用插空法，枚举这 n 个数中有 i 个 1，然后有 n - i + 1 个空可以插，所以 C(n - i + 1, i) 即可
但是 n = 1e18
第一种情况 = C(n + 1, 0) + C(n, 1) + C(n - 1, 2) + C(n - 2, 3) + ... C(n / 2 + 1, n - n / 2)
第二种情况 = 2^n - 第一种情况
第一种情况可以改成用 dp 求解，dp[i] 表示 i 个数经过上述运算得到 0 的方案数，dp[i] = dp[i - 1] + dp[i - 2]
i - 1 为 i 选 0，i - 2 为 i 选 1
dp[1] = 2
dp[2] = 3
dp[3] = 5
*/

int T;
ULL n, k, l;
LL mod;
vector<vector<LL>> transfer;

void solve1() {
    cin >> n >> k >> l >> mod;
    vector<LL> r1, r2;
    r1.pb(0);
    r1.pb(1);
    r2.pb(1);
    r2.pb(1);
    transfer.pb(r1);
    transfer.pb(r2);
    vector<vector<LL>> cur;
    vector<LL> r3;
    r3.pb(1);
    r3.pb(2);
    cur.pb(r3);

    // 0, 1 -> n - 1, n, 需要递推 n - 1 次
    vector<vector<LL>> final_transfer = matrix_qpow(transfer, n - 1, mod);
    vector<vector<LL>> res_matrix = matrix_mul(cur, final_transfer, mod);
    LL res = 1 % mod, contrib0 = res_matrix[0][1], contrib1 = ((qpow(2, n, mod) - contrib0) % mod + mod) % mod;
    for (ULL i = 0; i < l; i++) {
        ULL bit = (k >> i) & 1ULL;
        if (bit == 0) {
            res *= contrib0;
        } else {
            res *= contrib1;
        }
        res %= mod;
    }
    if (l <= 63 && (k >> l)) {
        res = 0;
    }
    cout << res % mod << "\n";
}                