/*
就是求 LCS，但是时间复杂度爆了
每种数不超过 k 次，k 比较小，有什么好的做法？
枚举 a[i]，则对于每个 a[i]，在 b 中至多有 k 个地方可能匹配
而 LCS 的转移方程中，真正能让答案变大的，就是 a[i] = b[j] 的时候
我们枚举 a[i] 在 b 中出现的所有位置，假设某个为 pos
则只需要看 a 的前 i - 1 个数和 b 的前 pos - 1 个数构成的 LCS 多长了
这个东西如何快速维护？
我们使用一个树状数组，去维护 b 的前 j 个位置和目前枚举的 a 的前缀分别能匹配多少地方
我们枚举 pos 的时候，由于需要用到 i - 1 的结果，所以需要从大到小枚举 pos
*/

int n, k, a[N], b[N], tr[N];

int lowbit(int x) {
    return x & -x;
}

void modify(int pos, int val) {
    while (pos <= n * k) {
        tr[pos] = max(tr[pos], val);
        pos += lowbit(pos);
    }
}

int query(int pos) {
    int res = 0;
    while (pos > 0) {
        res = max(res, tr[pos]);
        pos -= lowbit(pos);
    }
    return res;
}

void meibao() {
    cin >> n >> k;
    int m = n * k;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    vector<vector<int>> pos(n + 1);
    for (int i = m; i > 0; i--) {
        pos[b[i]].push_back(i);
    }

    for (int i = 1; i <= m; i++) {
        int val = a[i];
        for (auto j : pos[val]) {
            modify(j, query(j - 1) + 1);
        }
    }
    cout << query(m) << "\n";
}   
