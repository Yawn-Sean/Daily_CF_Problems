/*
首先要求变换次数最小，然后要求字典序最小
先求最小变换次数，把相同字符都删了，则剩下的都是要转化
变换时，肯定是越靠左的越改成字典序小的字符
原字符可能本来字典序更小，比如 ABA 到 CBA，需要把一个 A 改成 C，这个时候则是尽量改靠后的 A
原字符字典序更大，则肯定是找尽可能靠后的字符改
不妨维护后缀中每种字符还剩多少个，以及每种字符还有多少个要被改
要保证每种字符剩的个数 >= 每种字符还要被改的个数
枚举要改成的目标，枚举位置：
- 当前位置的字符不是要被改动的字符，则看下一个
- 当前位置的字符可以被改动
  - 当前字符字典序 >= 目标字符，则直接改
  - 当前字符字典序 < 目标字符，如果右边每种字符剩的个数 >= 每种字符还要被改的个数，则继续往后看，否则只能改了
*/

string s, t;
int n, cnt[3][26], sum[N][26];

void meibao() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> s >> t;
    n = s.size();
    s = " " + s;
    t = " " + t;
    for (int i = 1; i <= n; i++) {
        cnt[0][s[i] - 'A']++;
        cnt[1][t[i] - 'A']++;
        for (int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j];
        }
        sum[i][s[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        int mn = min(cnt[0][i], cnt[1][i]);
        cnt[0][i] -= mn;
        cnt[1][i] -= mn;
    }

    int res = 0;
    for (int i = 0; i < 26; i++) {
        res += cnt[0][i];
    }
    cout << res << "\n";

    vector<char> target;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[1][i]; j++) {
            char ch = char('A' + i);
            target.push_back(ch);
        }
    }

    int i = 1;

    auto enough = [&] (int pos) -> bool {
        bool ok = true;
        for (int i = 0; i < 26; i++) {
            ok &= (sum[n][i] - sum[pos - 1][i] >= cnt[0][i]);
        }
        return ok;
    };

    for (auto ch : target) {
        for ( ; i <= n; i++) {
            if (cnt[0][s[i] - 'A'] != 0) {
                if (s[i] >= ch) {
                    cnt[0][s[i] - 'A']--;
                    cnt[1][ch - 'A']--;
                    s[i] = ch;
                    i++;
                    break;
                } else {
                    if (!enough(i + 1)) {
                        cnt[0][s[i] - 'A']--;
                        cnt[1][ch - 'A']--;
                        s[i] = ch;
                        i++;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        assert(cnt[0][i] == 0);
        assert(cnt[1][i] == 0);
    }

    for (int i = 1; i <= n; i++) {
        cout << s[i];
    }
}
