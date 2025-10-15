/*
把相同颜色的方块放在一起
对于每种颜色的方块，看在至多删除 k 个方块其他情况下，这种颜色的方块至多能多长，双指针即可
*/

int n, m, k, a[N];
vector<vector<int>> pos(N);

void meibao() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    int res = 0;
    for (int i = 1; i <= m; i++) {
        if (pos[i].size() != 0) {
            int l = 0, r = 0, deleted_cnt = 0, len = 0;
            for ( ; r < pos[i].size(); r++) {
                len++;
                deleted_cnt += (l == r ? 0 : (pos[i][r] - pos[i][r - 1] - 1));
                while (deleted_cnt > k && l < r) {
                    deleted_cnt -= pos[i][l + 1] - pos[i][l] - 1;
                    l++;
                    len--;
                }
                res = max(res, len);
            }
        }
    }
    cout << res << "\n";
}
