/*
长度为 k 的子串，分三类，RGB... GBR... BRG...
假如 s[1...k] 需要修改 cnt 个，则 s[2...k + 1] 只需要看 k + 1 处是否需要修改，以及 1 处是否需要修改
枚举这三种模式，分别做一遍
*/

int T;
int n, k;
string s;

int calc(char ch[]) {
    int cnt = 0;
    int res = n;
    int st = 0, ed = 0;
    for (int i = 0; i < k; i++, ed++) {
        if (s[i] != ch[ed % 3]) {
            cnt++;
        }
    }
    res = min(res, cnt);
    for (int i = 1; i + k - 1 < n; i++, st++, ed++) {
        int j = i + k - 1;
        if (s[i - 1] != ch[st % 3]) {
            cnt--;
        }
        if (s[j] != ch[ed % 3]) {
            cnt++;
        }
        res = min(res, cnt);
    }
    return res;
}

void solve1() {
    cin >> n >> k >> s;
    int res = n;
    char ch[3] = {'R', 'G', 'B'};
    res = min(res, calc(ch));
    ch[0] = 'G', ch[1] = 'B', ch[2] = 'R';
    res = min(res, calc(ch));
    ch[0] = 'B', ch[1] = 'R', ch[2] = 'G';
    res = min(res, calc(ch));
    cout << res << "\n";
}                                                                                                                  
