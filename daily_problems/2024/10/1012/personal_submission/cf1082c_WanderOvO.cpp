/*
按照科目去存等级，等级降序排序
需要选一些科目，每个科目出的人数一样多，最后总和等级
维护一个答案数组 res，res[i] 表示选的科目中每个科目出 i 个人的最大和，初始都是 0
每个组累加最大的 i 个，然后贡献到 res[i] 中，如果是负数就贡献 0
*/

LL n, m;
vector<vector<LL>> e(N); 
vector<LL> res(N, 0);

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        LL s, r;
        cin >> s >> r;
        e[s].pb(r);
    }
    for (int i = 1; i <= m; i++) {
        sort(e[i].begin(), e[i].end());
        reverse(e[i].begin(), e[i].end());
        LL sum = 0;
        for (int j = 0; j < e[i].size(); j++) {
            sum += e[i][j];
            res[j + 1] += max(sum, 0LL);
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, res[i]);
    }
    cout << ans << "\n";
} 
