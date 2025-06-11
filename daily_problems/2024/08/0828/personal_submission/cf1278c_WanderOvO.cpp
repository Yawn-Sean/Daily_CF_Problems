/*
最坏的情况大不了就是全都吃了
我们枚举左边剩下了几个罐子，算一下红色 - 蓝色的个数，记为 cnt
然后看右边，其实就是看右边的最长的后缀，满足红色 - 蓝色 = -cnt
*/

int T;
int a[2 * N], n;
int cnt[3][2 * N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        cnt[1][i] = cnt[1][i - 1];
        cnt[2][i] = cnt[2][i - 1];
        cnt[a[i]][i]++;
    }
    map<int, int> max_len;
    max_len[0] = 0;
    for (int i = 2 * n; i > n; i--) {
        int red_cnt = cnt[1][2 * n] - cnt[1][i - 1];
        int blue_cnt = cnt[2][2 * n] - cnt[2][i - 1];
        int c = red_cnt - blue_cnt;
        max_len[c] = 2 * n - i + 1;
    }
    int res = 0;
    for (int i = 0; i <= n; i++) {
        int red_cnt = cnt[1][i];
        int blue_cnt = cnt[2][i];
        int c = red_cnt - blue_cnt;
        c *= -1;
        if (max_len.count(c)) {
            res = max(res, max_len[c] + i);
        }
    }
    cout << 2 * n - res << "\n";
}                
