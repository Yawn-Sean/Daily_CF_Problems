/*
每对球员在不同的球队中至少有一次训练
第一轮，某些人在同一个队里面
第二轮，原本在同一个队的人均分，一半保留在原队，另一半到对方队伍里
一直递归，把每个小区间都做这样的处理
*/

int n;
vector<vector<int>> res(N);

void dfs(int level, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    for (int i = l; i <= mid; i++) {
        res[level].push_back(i);
    }
    dfs(level + 1, l, mid);
    dfs(level + 1, mid + 1, r);
}

void meibao() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    int cnt = 0;
    for (int i = 0; (1 << i) < n; i++) {
        cnt++;
    }
    cout << cnt << "\n";
    
    dfs(1, 1, n);

    for (int i = 1; i <= cnt; i++) {
        cout << res[i].size() << " ";
        for (auto val : res[i]) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
