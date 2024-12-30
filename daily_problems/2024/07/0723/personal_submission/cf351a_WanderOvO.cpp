/*
只需要考虑小数部分
除去小数部分后，有 n 个数向上取整，n 个数向下取整
如果除去小数部分后为 0，则不管向上还是向下都是 0
如果不为 0，则向下为 0，向上为 1
假设有 zerocnt 个 0，我们枚举这 zerocnt 个 0 里面有多少个是向下取整的，即可算出来总和，再算差值
听羊神的，由于固定是 3 位小数，所以直接转成整数算
*/

int T;
int n;

void solve1() {
    cin >> n;

    int sum = 0, zerocnt = 0;

    for (int i = 0; i < 2 * n; i++) {
        string s;
        cin >> s;
        int val = 0;
        for (int j = s.size() - 3; j < s.size(); j++) {
            val = 10 * val + (s[j] - '0');
        }
        sum += val;
        if (val == 0) {
            zerocnt++;
        }
    }

    int res = 2000 * n;

    for (int i = max(n - zerocnt, 0); i <= min(2 * n - zerocnt, n); i++) {
        res = min(res, abs(1000 * i - sum));
    }

    cout << res / 1000 << '.';
    res %= 1000;
    cout << res / 100 << res / 10 % 10 << res % 10 << "\n";
}         