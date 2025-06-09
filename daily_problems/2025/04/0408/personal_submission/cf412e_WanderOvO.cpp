/*
先找相邻的 @ 和 . 的位置，这两个位置中间不能有特殊字符
然后往左右延申，看能延伸多少，乘一下就好
注意 A B C 各自的限制条件，有所不同
- A: 我们需要知道每个 @ 的左边第一个小写字母的位置，以及左边第一个 @ 和 . 的位置的 max
  这两个位置之间的小写字母的个数，就是 A 的可选范围（事实上就是合法的第一个字母的选择方案数）
- B: 我们需要判断当前 @ 与其右边第一个 . 之间的部分是否符合 B 的定义，即是否只包含小写字符和数字，即是否不包括下划线和 @.
- C: 我们需要知道 . 的右边最长能有多长的连续的小写字母
可以预处理字符次数前缀和，以及各种左边/右边第一个位置
*/

string s;
int left_at[N], left_point[N], left_alphabet[N], right_point[N], right_len[N];
int alphabet_cnt[N], digit_cnt[N], point_cnt[N], at_cnt[N], slice_cnt[N];

void meibao() {
    cin >> s;
    int n = s.size();
    s = " " + s;
    left_at[1] = 0;
    left_point[1] = 0;
    left_alphabet[1] = 0;
    for (int i = 2; i <= n; i++) {
        left_at[i] = left_at[i - 1];
        left_point[i] = left_point[i - 1];
        left_alphabet[i] = left_alphabet[i - 1];
        if (s[i - 1] == '@') {
            left_at[i] = i - 1;
        }
        if (s[i - 1] == '.') {
            left_point[i] = i - 1;
        }
        if (islower(s[i - 1])) {
            left_alphabet[i] = i - 1;
        }
    }

    right_point[n] = n + 1;
    right_len[n] = 0;

    for (int i = n - 1; i > 0; i--) {
        right_point[i] = right_point[i + 1];
        if (s[i + 1] == '.') {
            right_point[i] = i + 1;
        }

        if (islower(s[i + 1])) {
            right_len[i] = right_len[i + 1] + 1;
        } else {
            right_len[i] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        alphabet_cnt[i] = alphabet_cnt[i - 1] + (islower(s[i]) ? 1 : 0);
        digit_cnt[i] = digit_cnt[i - 1] + (isdigit(s[i]) ? 1 : 0);
        point_cnt[i] = point_cnt[i - 1] + (s[i] == '.' ? 1 : 0);
        at_cnt[i] = at_cnt[i - 1] + (s[i] == '@' ? 1 : 0);
        slice_cnt[i] = slice_cnt[i - 1] + (s[i] == '_' ? 1 : 0);
    }

    LL res = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '@') {
            int l = max(left_at[i], left_point[i]);
            int r = left_alphabet[i];
            LL a_cnt = (l < r ? (alphabet_cnt[r] - alphabet_cnt[l]) : 0);

            int point_pos = right_point[i];
            LL b_cnt = 1;
            if (point_pos > n) {
                b_cnt = 0;
            } else if (at_cnt[point_pos] - at_cnt[i] > 0) {
                b_cnt = 0;
            } else if (slice_cnt[point_pos] - slice_cnt[i] > 0) {
                b_cnt = 0;
            } else if (point_pos == i + 1) {
                b_cnt = 0;
            }
            
            if (point_pos <= n) {
                LL c_cnt = right_len[point_pos];
                res += a_cnt * b_cnt * c_cnt;
            }   
        }
    }
    cout << res << "\n";
}
