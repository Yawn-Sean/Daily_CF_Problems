/*
哈希+DP实在过不去

可以直接暴力匹配做
s 和 rev_s 为未翻转和翻转的结果
t 直接和 s 以及 rev_s 进行匹配，看最长能匹配多少
下一轮从 t 的未匹配上的第一位开始重新再跑匹配
每轮匹配复杂度不超过 O(nl)，其中 l 是本轮最大的被匹配上的长度
而所有轮匹配加起来 sum(l) = m，所以总复杂度不超过 O(nm)
*/

string s, t;

void meibao() {
    cin >> s >> t;
    int idx = 0, n = s.size(), m = t.size();
    vector<PII> res;
    while (idx < m) {
        int maxlen = 0, l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[idx]) {
                int j;
                for (j = 0; i + j < n && idx + j < m && s[i + j] == t[idx + j]; j++);
                if (j > maxlen) {
                    maxlen = j;
                    l = i;
                    r = i + j - 1;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == t[idx]) {
                int j;
                for (j = 0; i - j >= 0 && idx + j < m && s[i - j] == t[idx + j]; j++);
                if (j > maxlen) {
                    maxlen = j;
                    l = i;
                    r = i - j + 1;
                }
            }
        }
        if (maxlen == 0) {
            cout << "-1\n";
            return;
        }
        res.push_back({l + 1, r + 1});
        idx += maxlen;
    }
    cout << res.size() << "\n";
    for (auto choice : res) {
        cout << choice.x << ' ' << choice.y << "\n";
    }
}
