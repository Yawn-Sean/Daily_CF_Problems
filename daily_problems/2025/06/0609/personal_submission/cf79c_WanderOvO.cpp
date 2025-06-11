/*
和前几天的茶差不多
对于每个被 ban 的字符串，求一下其出现的开始位置
枚举右，维护左，随着右端点增大，左端点也只能单调增大，可以双指针或二分
*/

string s, ban[M];
int n;

void meibao() {
    cin >> s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ban[i];
    }
    vector<vector<int>> pos(n + 1);
    for (int j = 1; j <= n; j++) {
        int len = ban[j].size();
        for (int i = 0; i + len - 1 < s.size(); i++) {
            if (s.substr(i, len) == ban[j]) {
                pos[j].push_back(i);
            }
        }
    }

    int max_len = 0, st_pos = 0;
    for (int i = 0; i < s.size(); i++) {
        int min_l = 0;
        for (int j = 1; j <= n; j++) {
            int len = ban[j].size();
            // target 为左端点的最小值，比这个还严格小就不行了
            int target = i - len + 2;
            int p = lower_bound(pos[j].begin(), pos[j].end(), target) - pos[j].begin() - 1;
            if (p >= 0) {
                min_l = max(min_l, pos[j][p] + 1);
            }
        }
        if (i - min_l + 1 > max_len) {
            max_len = i - min_l + 1;
            st_pos = min_l;
        }
    }
    cout << max_len << " " << st_pos << "\n";
}
