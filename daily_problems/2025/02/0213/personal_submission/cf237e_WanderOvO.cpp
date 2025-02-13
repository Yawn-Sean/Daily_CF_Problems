/*
如果目标串只有一种字符，只需要从第一个串开始贪心就好了
如果目标串只有两种字符（01串），dp[i][j][k] 表示前 i 个字符串，凑出了 j 个 0 和 k 个 1 的最小代价
dp[i][j][k] = min(dp[i - 1][j - cnt1][k - cnt2] + (cnt1 + cnt2) * i)，cnt1 + cnt2 <= a[i]
但是字符种类太多之后状态空间就炸了
感觉得用图进行建模，不太懂

羊神提示：没想到吧，这个得用费用流
0 为源点，1-n 为字符串，n + 1 到 n + 26 为 a-z，n + 27 为汇点
*/

void meibao() {
    string s;
    cin >> s;

    int cnt[26] = {0};
    for (auto ch : s) {
        cnt[ch - 'a']++;
    }
    int n;
    cin >> n;
    atcoder::mcf_graph<int, int> mcf(n + 28);
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0)
            mcf.add_edge(n + i + 1, n + 27, cnt[i], 0);
    }

    for (int i = 1; i <= n; i++) {
        string t;
        int a;
        cin >> t >> a;
        memset(cnt, 0, sizeof cnt);
        for (auto ch : t) {
            cnt[ch - 'a']++;
        }
        mcf.add_edge(0, i, a, i);
        for (int j = 0; j < 26; j++) {
            if (cnt[j] > 0)
                mcf.add_edge(i, n + j + 1, cnt[j], 0);
        }
    }

    auto res = mcf.flow(0, n + 27);
    if (res.first == s.size()) {
        cout << res.second << "\n";
    } else {
        cout << "-1\n";
    }
}
