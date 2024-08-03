/*
ax + by = c
询问数只有 20
我们先只预处理一种纸币能拼出来的结果，并且把最少都维护一下，大概维护 1e4 个结果
对于每次询问 x，我们直接遍历能拼出来的 <= x 的结果集
遍历到 val，看 x - val 是否在答案里面，在的话，把 val 和 x - val 的方案看一下，两个的最小加起来即可
*/

int T;
map<int, int> min_cnt;
int n, k, a[N], q;

void solve1() {
    cin >> n >> k;
    min_cnt[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= k; j++) {
            int val = a[i] * j;
            if (min_cnt.count(val)) {
                min_cnt[val] = min(min_cnt[val], j);
            } else {
                min_cnt[val] = j;
            }
        }
    }
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int res = k + 1;
        for (auto it : min_cnt) {
            int val1 = it.x;
            int val2 = x - val1;
            if (min_cnt.count(val2)) {
                res = min(res, min_cnt[val1] + min_cnt[val2]);
            }
        }
        if (res <= k) {
            cout << res << "\n";
        } else {
            cout << "-1\n";
        }
    }
}                 