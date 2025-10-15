/*
先把所有的 0 放到最后边，这最优吗？不一定
0 如何得到的？0 + 0，或加起来是 10，或加起来是 9 + 进位
其实是一段 0，一个 10 和一段 9
找一对数，加起来是 10，这对数可以枚举，一共有 9 种可能
应该先凑和是 9 的，剩下的 0 凑和是 0 的，这样能凑出尽可能长的
上面那对数枚举之后，后边就是尽可能凑出来相加为 9 的了，贪心匹配就行了
*/

string s;
int n, cnt[2][10];

void meibao() {
    cin >> s;
    n = s.size();
    for (auto ch : s) {
        cnt[0][ch - '0']++;
        cnt[1][ch - '0']++;
    }
    
    vector<int> s1, s2;

    int d1 = -1, d2 = -1, max_cnt = 0;
    for (int i = 1; i < 10; i++) {
        if (cnt[0][i] && cnt[1][10 - i]) {
            int len = 1;
            // 10
            cnt[0][i]--;
            cnt[1][10 - i]--;
            // 9
            for (int j = 0; j < 10; j++) {
                int c = min(cnt[0][j], cnt[1][9 - j]);
                len += c;
            }
            // 0
            len += min(cnt[0][0], cnt[1][0]);
            
            if (len > max_cnt) {
                max_cnt = len;
                d1 = i;
                d2 = 10 - i;
            }
            cnt[0][i]++;
            cnt[1][10 - i]++;
        }
    }

    if (d1 == -1) {
        // 没有 10，只能把 0 放最后
        for (int i = 0; i < cnt[0][0]; i++) {
            s1.push_back(0);
            s2.push_back(0);
        }
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < cnt[0][i]; j++) {
                s1.push_back(i);
                s2.push_back(i);
            }
        }
    } else {
        s1.push_back(d1);
        s2.push_back(d2);
        cnt[0][d1]--;
        cnt[1][d2]--;
        for (int i = 0; i < 10; i++) {
            int c = min(cnt[0][i], cnt[1][9 - i]);
            cnt[0][i] -= c;
            cnt[1][9 - i] -= c;
            for (int j = 0; j < c; j++) {
                s1.push_back(i);
                s2.push_back(9 - i);
            }
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        while (cnt[0][0] && cnt[1][0]) {
            s1.push_back(0);
            s2.push_back(0);
            cnt[0][0]--;
            cnt[1][0]--;
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < cnt[0][i]; j++) {
                s1.push_back(i);
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < cnt[1][i]; j++) {
                s2.push_back(i);
            }
        }
    }

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for (auto v : s1) {
        cout << v;
    }
    cout << "\n";
    for (auto v : s2) {
        cout << v;
    }
}
