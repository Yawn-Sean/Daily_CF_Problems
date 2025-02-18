/*
考虑维护每个数的最左和最右位置，最左到最右连一条线段
一个区间是合法的，当且仅当其包含的线段都是完整的
能否预处理出所有合法的区间？并预处理出每个合法区间的满足条件的异或和？
如何判断一个区间合法？
强行枚举所有区间，每遇到一个新的数，就计算这个区间里包含所有数的最左和最右位置
区间和最左最右位置完全对的上时，区间才是合法的
枚举区间时，顺便维护区间内数字出现的次数，这样合法区间的异或和也预处理出来了
把所有右端点相同的区间放在一起，存左端点以及异或和
这样之后就可以做一个 dp，考虑前 i 个元素分段最大是多少
枚举以 i 为右端点的合法区间，假设左端点是 l
dp[i] = max(dp[l - 1] + 这个区间的 xor)
总复杂度不会超过 O(n^2)
*/

int n, dp[M], a[N];;
int l[M], r[M];
vector<vector<PII>> segs(M);

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (l[a[i]] == 0) {
            l[a[i]] = i;
        }
        r[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        int left = l[a[i]], right = r[a[i]];
        vector<int> cnt(M, 0);
        int xor_sum = 0;
        for (int j = i; j <= n; j++) {
            left = min(left, l[a[j]]);
            right = max(right, r[a[j]]);
            cnt[a[j]]++;
            if (cnt[a[j]] == 1) {
                xor_sum ^= a[j];
            }
            if (left == i && right == j) {
                segs[j].pb({i, xor_sum});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < segs[i].size(); j++) {
            int k = segs[i][j].x - 1, val = segs[i][j].y;
            dp[i] = max(dp[i], dp[k] + val);
        }
    }
    cout << dp[n] << "\n";
}   
