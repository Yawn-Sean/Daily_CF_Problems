/*
先求一个前缀和
枚举左端点，考虑以这个为起点，所有前缀最大值变化的点
假设左端点是 l，则从小到大枚举 r
最开始记和为 0，则第一个变化的点就是第一个 > sum[l - 1] 的位置，假设是 r0
则下一个要找的 r1 就是第一个满足 sum[r1] > sum[r0] 的位置
所以，我们不妨在求出所有 sum[l] 之后，考虑右边第一个比自己严格大的位置是谁，预处理出来
假设是 pos[l]，则 r in [l, pos[l - 1] - 1] 时，贡献的都是 0
r 从 pos[l - 1] 开始，到 pos[pos[l - 1]] - 1，贡献就是 sum[pos[l - 1]] - sum[l - 1] 了
我们相当于把 r 从 [l, n]，拆成了若干段，然后分别计算贡献
注意到每段的贡献是段长度 * (sum[段开始的位置] - sum[l - 1])
其中 sum[l - 1] 可以提出来，所以本质上就是段长度 * sum[段开始的位置]
我们从大到小枚举 l，事实上只要看 r in [l, pos[l - 1] - 1] 这段就好了，把这段的长度 * sum[l - 1] 算出来
然后加上之前已经算好的 pos[l - 1] 之后的部分的所有的段长度 * sum 的和
最后减去 n - l + 1 倍的 sum[l - 1] 就好了

具体计算时，枚举到 l 了
先把 [l, pos[l - 1] - 1] 这段的贡献加起来，是 sum[l - 1]
然后对于 [pos[l - 1], n] 的贡献，如果 pos[l - 1] > l，则已经算出来了，直接加即可
如果 pos[l - 1] = l，则我们关心的就是第一个 > s[l] 的位置是谁了，也就是 pos[l]
从 [pos[l - 1], pos[l] - 1]，贡献都是 s[l]
*/

LL n, a[N], s[N], pos[N], b[N], rk[N];
LL dp[N];
SegmentTree smt;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        b[i] = s[i];
    }
    b[n + 1] = 0;
    sort(b + 1, b + n + 2);
    
    for (int i = 1; i <= n + 1; i++) {
        dp[i] = 0;
    }
    smt.init(n + 1);
    for (int l = n; l >= 0; l--) {
        rk[l] = lower_bound(b + 1, b + n + 2, s[l]) - b;
        
        int p;
        if (rk[l] == n + 1) {
            p = n + 1;
        } else {
            p = smt.query(1, n + 1, rk[l] + 1, n + 1, 1);
            if (p > INF / 2) {
                p = n + 1;
            }
        }
        
        pos[l] = p;
        smt.modify(1, n + 1, 1, rk[l], l);
    }
    
    LL res = 0;
    for (int l = n; l > 0; l--) {
        LL sum = 0;
        sum += (pos[l - 1] - l) * s[l - 1];
        if (pos[l - 1] == l) {
            sum += (pos[l] - l) * s[l];
            sum += dp[pos[l]];
            dp[l] = sum;
        } else {
            sum += dp[pos[l - 1]];
            dp[l] = sum;
        }
        
        sum -= (n - l + 1) * s[l - 1];
        res += sum;
    }
    cout << res << "\n";
}
