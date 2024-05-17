/*
假如翻转 [1, k] 和 [k + 1, n]，则 [1, k] 和 [k + 1, n] 各自内部的最长交替串不变
手玩可以发现，翻转一次其实就是把一个前缀交替串和一个后缀交替串拼接成一个更长的
如果前缀是 w 开头，则后缀必须是 b 结尾，才可能拼到更长的
看原本最长是多长，然后前后缀再合并一下即可

多次翻转是否真的有效果？第二次操作其实就是把刚才掰开的再合回去，没啥用
*/

int T;
string s;
int n;

void solve1() {
    cin >> s;
    n = s.size();
    s = " " + s;
    int res = 1, curlen = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            curlen++;
        } else {
            curlen = 1;
        }
        res = max(res, curlen);
    }

    int max_prefix = 1, max_sufix = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            max_prefix++;
        } else {
            break;
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (s[i] != s[i + 1]) {
            max_sufix++;
        } else {
            break;
        }
    }
    if (s[1] != s[n]) {
        res = max(res, min(n, max_prefix + max_sufix));
    }
    cout << res << endl;
}       