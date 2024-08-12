/*
字符串长度比较短，感觉可以相对暴力地回答每次询问
对于每次询问，假如可以把至多 m 个字符变成 ch，先计算 ch 出现次数的前缀和
枚举最长的那个串的右端点 r，看 l 最多能到哪里
(r - l + 1) - (cnt[r] - cnt[l - 1]) <= m 才行
r - (l - 1) - cnt[r] + cnt[l - 1] <= m
cnt[l - 1] - (l - 1) <= m + cnt[r] - r，找最小的满足条件的
使用权值树状数组，往 cnt[i] - i 位置单点更新 i，然后前缀查询最小值
为了防止越界，都加一个 n + 1，往 n + 1 + cnt[i] - i 位置单点更新 i，查 <= n + 1 + m + cnt[r] - r 的最小的 l - 1
注意到 m, ch 范围很小，所以可以把所有答案预先算出来，然后直接查表
*/

int T;
int cnt[N], q, n;
string s;
BIT bit;
int res[N][M];

void solve1() {
    cin >> n >> s;
    s = " " + s;
    for (int m = 1; m <= n; m++) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            for (int i = 1; i <= n; i++) {
                cnt[i] = cnt[i - 1] + (s[i] == ch);
            }
            bit.init(n + 1);
            bit.modify(n + 1, 0);
            for (int r = 1; r <= n; r++) {
                int target = n + 1 + m + cnt[r] - r;
                target = min(target, n + 1);
                int l = bit.query(target);
                // cout << l << " " << r << "\n";
                res[m][ch - 'a'] = max(res[m][ch - 'a'], r - l);
                bit.modify(n + 1 + cnt[r] - r, r);
            }
        }
    }
    cin >> q;
    while (q--) {
        int m;
        char ch;
        cin >> m >> ch;
        cout << res[m][ch - 'a'] << "\n";
    }
}      
