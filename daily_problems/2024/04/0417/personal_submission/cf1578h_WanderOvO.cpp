/*
s = ()
s = (s)
s = s -> s

((() -> ()))
使用递归下降模拟即可
*/

int T;
string s;
int idx = 0, n;

// 左括号进
int parse() {
    if (s[idx] != '(') {
        cout << "fuck\n";
        return -1;
    }
    
    idx++;
    int res1 = -1, res2 = -1;
    if (s[idx] == ')') {
        // 分析到了最内层括号
        idx++;
        res1 = 0;
        if (idx < n && s[idx] == '-') {
            idx += 2;
            res2 = parse();
            return max(res1 + 1, res2);
        }
        return res1;
    } else {
        int res1 = parse();
        if (s[idx] == ')') {
            idx++;
        } else {
            cout << "fuck\n";
            return -1;
        }
        int res2 = -1;
        if (idx < n && s[idx] == '-') {
            idx += 2;
            res2 = parse();
            return max(res1 + 1, res2);
        }
        return res1;
    }
}

void solve1() {
    cin >> s;
    n = s.size();
    cout << parse() << "\n";
}