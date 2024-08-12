/*
有点类似森林的边数 = 点数 - 连通块个数
操作次数 = 总共的 . 的数量 - . 的段数
只需要维护 . 的数量和 . 的段数即可
分组循环预处理段数和点数
*/

int T;  
string s;
int n, m;

void solve1() {
    cin >> n >> m >> s;
    int dot_cnt = 0, dot_seg_cnt = 0;
    for (int i = 0; i < s.size(); ) {
        if (s[i] != '.') {
            i++;
            continue;
        }
        int st = i;
        i++;
        for ( ; i < s.size() && s[i] == '.'; i++);
        dot_cnt += i - st;
        dot_seg_cnt++;
    }
    while (m--) {
        int pos;
        char ch;
        cin >> pos >> ch;
        pos--;
        if (s[pos] == '.') {
            if (ch != '.') {
                s[pos] = ch;
                dot_cnt--;
                if (pos - 1 >= 0 && pos + 1 < s.size()) {
                    if (s[pos - 1] == '.' && s[pos + 1] == '.') {
                        dot_seg_cnt++;
                    } else if (s[pos - 1] != '.' && s[pos + 1] != '.') {
                        dot_seg_cnt--;
                    }
                } else if (pos - 1 >= 0) {
                    if (s[pos - 1] != '.') {
                        dot_seg_cnt--;
                    }
                } else if (pos + 1 < s.size()) {
                    if (s[pos + 1] != '.') {
                        dot_seg_cnt--;
                    }
                } else {
                    dot_seg_cnt--;
                }
            }
        } else {
            if (ch == '.') {
                s[pos] = ch;
                dot_cnt++;
                if (pos - 1 >= 0 && pos + 1 < s.size()) {
                    if (s[pos - 1] != '.' && s[pos + 1] != '.') {
                        dot_seg_cnt++;
                    } else if (s[pos - 1] == '.' && s[pos + 1] == '.') {
                        dot_seg_cnt--;
                    }
                } else if (pos - 1 >= 0) {
                    if (s[pos - 1] != '.') {
                        dot_seg_cnt++;
                    }
                } else if (pos + 1 < s.size()) {
                    if (s[pos + 1] != '.') {
                        dot_seg_cnt++;
                    }
                } else {
                    dot_seg_cnt++;
                }
            }
        }
        // cout << dot_cnt << " " << dot_seg_cnt << "\n";
        cout << dot_cnt - dot_seg_cnt << "\n";
    }
}