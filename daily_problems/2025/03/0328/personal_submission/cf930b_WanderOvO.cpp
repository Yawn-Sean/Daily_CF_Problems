/*
先构造两倍的字符串
如何确定字符串？
由于第 1 个字符一定会被选，我们其实是在已知第 1 个字符为 ch 的情况下，找一个最好的 i，能区分尽可能多的情况
预处理每种字符 ch 出现的所有位置
枚举所有字符 ch，枚举距离 d，枚举 ch 出现的所有位置，看 d 的情况下有多少种可能是完全可区分的，找最多的那个统计到答案中
*/

string s;
int n;

void meibao() {
    cin >> s;
    n = s.size();
    string t = s + s;
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        pos[ch - 'a'].push_back(i);
    }

    int res = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        int max_cnt = 0;
        for (int d = 1; d < n; d++) {
            int cnt[26] = {0};
            int can_determine_cnt = 0;
            for (auto p : pos[ch - 'a']) {
                cnt[t[p + d] - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 1) {
                    can_determine_cnt++;
                }
            }
            max_cnt = max(max_cnt, can_determine_cnt);
        }
        res += max_cnt;
    }
    cout << setprecision(15) << (1.0 * res) / n << "\n";
}
