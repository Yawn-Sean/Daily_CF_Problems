/*
考虑以第 i 个字符结尾的子串，i 前面至多有 26 个 d(s) 的变化点
维护第 i 个字符左边(包括自己)第一个 ch 字符的位置
把这些位置排个序，这些就是变化的位置，不同位置之间的长度就是某个 d(s) 的出现次数
*/

int T;
LL pos[N][27], n, res[27];
char s[N];

void solve1() {
    cin >> (s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            pos[i][j] = pos[i - 1][j];
        }
        if (i > 1) {
            pos[i][s[i - 1] - 'a'] = i - 1;
        }
        pos[i][s[i] - 'a'] = i;
        vector<int> p;
        for (int j = 0; j < 26; j++) {
            if (pos[i][j]) {
                p.pb(pos[i][j]);
            }
        }
        
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        int last = i;
        for (int j = 1; j < p.size(); j++) {
            res[j] += last - p[j];
            last = p[j];
        }
        res[p.size()] += last;
    }
    int cnt = 0;
    for (int i = 1; i <= 26; i++) {
        if (res[i] > 0) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++) {
        cout << res[i] << "\n";
    }
}        