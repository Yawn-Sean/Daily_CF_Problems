/*
如果操作偶数次可以，则相当于交换 a 原串中的 0 和 1，使得最终变成 b
这种情况下只要 a 中的 1 和 b 中的 1 个数相等，即可做到
这种情况下最小操作次数就是 a 中为 1 但 b 中为 0 的位置的个数 * 2
如果操作奇数次可以，则先操作一次，然后只需要再操作偶数次
只要存在一种情况，使得操作一次之后，两边的 1 的个数相等，则可以
在上述条件下，我们要找一个位置，使得 a 中为 0 且 b 中为 0 的位置的个数最少
*/

int T;
int n;
string a, b;

void solve1() {
    cin >> n >> a >> b;
    int cnta[2] = {0}, cntb[2] = {0};
    for (int i = 0; i < n; i++) {
        cnta[a[i] - '0']++;
    }
    for (int i = 0; i < n; i++) {
        cntb[b[i] - '0']++;
    }
    int res = INF;
    if (cnta[1] == cntb[1]) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '1' && b[i] == '0') {
                ans += 2;
            }
        }
        res = min(res, ans);
    }
    int both_zero_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0' && b[i] == '0') {
            both_zero_cnt++;
        }
    }
    for (int i = 0; i < n; i++) {
        // 选择 i，翻转其他部分后的 1 的个数
        if (a[i] != '1') continue;
        int new_one_cnt = cnta[0];
        if (a[i] == '0') {
            new_one_cnt--;
        } else {
            new_one_cnt++;
        }
        if (new_one_cnt == cntb[1]) {
            if (a[i] == '1' && b[i] == '0') {
                res = min(res, 2 * both_zero_cnt + 3);
            } else {
                res = min(res, 2 * both_zero_cnt + 1);
            }
        }
    }
    if (res == INF) {
        cout << "-1\n";
    } else {
        cout << res << "\n";
    }
}             