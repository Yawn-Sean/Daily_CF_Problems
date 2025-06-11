/*
只要保证没有 2 和 3 长度的回文串即可
为了保证字典序最小，尽量让新的串和原串的尽可能长的前缀相等
从后往前枚举第一个开始不同的位置，然后枚举这个位置填什么
先看一下这个位置上填的是否符合题意，然后看后面怎么填
后面就尽力保证不出现连续两个相同，或者隔一个相同，保证这个的基础上往小了填
*/

int T;

void solve1() {
    int n, p;
    string s;
    cin >> n >> p >> s;
    string res = s;
    char max_char = p + 'a' - 1;
    for (int i = n - 1; i >= 0; i--) {
        bool can_finished = false;
        for (char ch = s[i] + 1; ch <= max_char; ch++) {
            bool first_ok = true;
            if (i >= 1 && s[i - 1] == ch) {
                first_ok = false;
            }
            if (i >= 2 && s[i - 2] == ch) {
                first_ok = false;
            }

            if (first_ok) {
                res[i] = ch;
                int j;
                for (j = i + 1; j < n; j++) {
                    bool filled = false;
                    for (char c = 'a'; c <= max_char; c++) {
                        if (j >= 1 && res[j - 1] == c) {
                            continue;
                        }
                        if (j >= 2 && res[j - 2] == c) {
                            continue;
                        }
                        filled = true;
                        res[j] = c;
                        break;
                    }
                    if (!filled) {
                        break;
                    }
                }
                if (j == n) {
                    can_finished = true;
                    break;
                }
            } 
        }
        if (can_finished) {
            cout << res << "\n";
            return;
        }
    }
    cout << "NO\n";
}            
