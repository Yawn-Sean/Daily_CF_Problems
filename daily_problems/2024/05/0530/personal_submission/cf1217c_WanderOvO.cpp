/*
区间长度至多为 2e5，所以 1 打头的区间长度不超过 20
所以所有以 1 开头的区间，只需要往后看至多 20 个位置即可
枚举长度 < 20 的以 1 开头的区间，暴力判断区间长度是否 = 数值
倘若长度 < 数值，则可以看 1 的左边有连续多少个 0，借位补过来
假设长度为 len，数值为 val，则看 1 左边是否有至少连续 val - len 个 0，有则可以
*/

int T;
string s;
int n, last_one_pos[N];

void solve1() {
    cin >> s;
    n = s.size();
    s = " " + s;
    last_one_pos[1] = 0;
    for (int i = 2; i <= n; i++) {
        last_one_pos[i] = (s[i - 1] == '1' ? (i - 1) : last_one_pos[i - 1]);
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            int val = 0;
            int left_zero = i - last_one_pos[i] - 1;
            for (int j = i; j <= min(i + 20, n); j++) {
                val = 2 * val + s[j] - '0';
                int len = j - i + 1;
                if (len == val) {
                    res++;
                } else if (len < val) {
                    if (len + left_zero >= val) {
                        res++;
                    }
                }
            }
        }
    }
    cout << res << "\n";
}    