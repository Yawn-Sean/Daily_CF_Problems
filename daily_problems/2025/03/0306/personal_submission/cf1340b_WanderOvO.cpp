/*
n, k = 2000
想从高位到低位贪心，但是有可能后边拼不出来合法的数字，或者次数还有剩余
先硬编码每个数字的数码管表示是多少
第 i 个数码管到数字 j 的距离记为 d[i][j]
我们想对每个 i 选一个 d[i][j]，求和之后恰好是 k，且最后的值最大
从小到大枚举 i，然后从大到小枚举 j，如何判断剩下的后缀是否可以恰好拼出一个合法的？
我们预处理 s[i][j]，表示从第 i 个到第 n 个，用恰好 j 次操作是否能拼出一个合法的数字
枚举把第 i 个数码管变成数字 val
s[i][j] |= s[i + 1][j - d[i][val]]
这样，从小到大枚举 i，然后从大到小枚举 j，维护现在剩余的次数 k，如果 s[i + 1][k - d[i][j]] 为真，说明能这样做
*/

bool s[M][M];
string a[M];
int n, k, d[M][M];
string nums[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int calc(string &a, string &b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '1' && b[i] == '0') {
            return INF;
        }

        if (a[i] == '0' && b[i] == '1') {
            res++;
        }
    }
    return res;
}

void meibao() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            d[i][j] = calc(a[i], nums[j]);
        }
    }

    s[n + 1][0] = true;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j <= k; j++) {
            for (int val = 0; val < 10; val++) {
                if (j >= d[i][val]) {
                    s[i][j] |= s[i + 1][j - d[i][val]];
                }
            }
        }
    }

    string res = "";
    for (int i = 1; i <= n; i++) {
        bool ok = false;
        for (int j = 9; j >= 0; j--) {
            if (k >= d[i][j] && s[i + 1][k - d[i][j]]) {
                k -= d[i][j];
                char ch = '0' + j;
                res += ch;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "-1\n";
            return;
        }
    }

    assert(k == 0);
    cout << res << "\n";
}   
