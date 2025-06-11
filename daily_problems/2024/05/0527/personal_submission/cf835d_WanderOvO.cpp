/*
不妨设所有串都至少是 0 阶回文串
所有长度为 1 的显然都是一阶回文串
按照长度枚举所有串，dp 求解
dp[l][r] 表示 s[l : r] 是 dp[l][r] 阶回文串
枚举到 dp[l][r] 时，len = r - l + 1
左半边是 s[l : l + len / 2 - 1]，右半边 s[r - len / 2 + 1 : r]
用哈希判断一下这两部分是否相等，并判断两边的串的阶数是否相等
似乎一个串可以是多种阶数的回文串，k 阶的一定是 k - 1 阶的
我们都按照最高阶来 dp，最后用大的累积到小的上面
*/

int T;
MyHash h;
string s;
int n, dp[N][N];

void solve1() {
    cin >> s;
    n = s.size();
    srand(time(NULL));
    int rand_mod = MOD1 + 1000 + rand() % 1000;
    h.init(s, P, rand_mod);
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (dp[l][l + len / 2 - 1] == dp[r - len / 2 + 1][r]) {
                if (h.get(l, l + len / 2 - 1) == h.rget(r - len / 2 + 1, r)) {
                    dp[l][r] = dp[l][l + len / 2 - 1] + 1;
                }
            }
        }
    }

    vector<LL> res(n + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            res[dp[i][j]]++;
        }
    } 
    for (int i = n; i > 0; i--) {
        res[i - 1] += res[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
}         