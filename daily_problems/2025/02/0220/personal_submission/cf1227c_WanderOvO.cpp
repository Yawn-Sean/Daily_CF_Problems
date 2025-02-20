/*
数据范围不大，似乎每次操作时暴力模拟翻转过程都来得及
输入保证是一个包含 n / 2 个左括号和右括号的括号序列
假设最后需要 k 个前缀是合法括号序列，先构造 k - 1 个 ()，剩下的再操作一下
*/

char s[N];
int n, k;

void my_reverse(int i, int j) {
    int p1 = i, p2 = j;
    while (p1 < p2) {
        swap(s[p1], s[p2]);
        p1++;
        p2--;
    }
}

void meibao() {
    cin >> n >> k >> (s + 1);
    int i = 1;
    vector<PII> res;
    for (int step = 1; step < k; step++) {
        int j = i;
        while (s[j] != '(' && j <= n) {
            j++;
        }
        assert(j <= n);
        my_reverse(i, j);
        res.push_back({i, j});
        i++;
        j = i;
        while (s[j] != ')' && j <= n) {
            j++;
        }
        assert(j <= n);
        my_reverse(i, j);
        res.push_back({i, j});
        i++;
    }
    int left_cnt = (n - (k - 1) * 2) / 2;
    for (int step = 1; step <= left_cnt; step++) {
        int j = i;
        while (s[j] != '(' && j <= n) {
            j++;
        }
        assert(j <= n);
        my_reverse(i, j);
        res.push_back({i, j});
        i++;
    }
    cout << res.size() << "\n";
    for (auto choice : res) {
        cout << choice.x << " " << choice.y << "\n";
    }
}
