/*
假如 s[i] 和 s[j] 中，s 的个数分别为 cnts[i], cnts[j]，h 的个数分别为 cnth[i], cnth[j]
如果 i 放前面，j 放后面，则贡献为 cnts[i] * cnth[j]，反之则是 cnts[j] * cnth[i]
如果 cnts[i] * cnth[j] 更大，则应该 i 放前面
*/

int T;
int n;
string s[N];
PLL a[N];

bool cmp(const PLL &p, const PLL &q) {
    LL contrib1 = p.x * q.y, contrib2 = q.x * p.y;
    return contrib1 > contrib2;
}

void solve1() {
    cin >> n;
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        int cnts = 0, cnth = 0;
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++) {
            if (s[i][j] == 'h') {
                cnth++;
                res += cnts;
            } else {
                cnts++;
            }
        }
        a[i] = {cnts, cnth};
    }
    
    sort(a + 1, a + n + 1, cmp);
    LL tots = 0;
    for (int i = 1; i <= n; i++) {
        res += tots * a[i].y;
        tots += a[i].x;
    }
    cout << res << "\n";
}           