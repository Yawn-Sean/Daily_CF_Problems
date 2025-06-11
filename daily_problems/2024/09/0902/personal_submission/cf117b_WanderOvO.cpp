/*
s1s2 能被 mod 整除则 B 获胜，否则 A 获胜
两个数都恰好是 9 位数
(s1 * 10^9 + s2) % mod = 0
0 <= s2 <= b
枚举 s1，看 -s1 * 10^9 的模数是否在 [0, b] 中
假如存在一个 s1，能够取模后不在里面，则说明 s1 能获胜，否则 s2 获胜
*/

int T;

void solve1() {
    int a, b, mod;
    cin >> a >> b >> mod;
    int mx = min(a, mod - 1);
    for (LL s1 = 0; s1 <= mx; s1++) {
        LL val = s1 * pow(10, 9);
        val *= -1;
        val %= mod;
        val = (val + mod) % mod;
        if (val > b) {
            cout << "1 ";
            vector<int> nums;
            while (s1 > 0) {
                nums.pb(s1 % 10);
                s1 /= 10;
            }
            while (nums.size() < 9) {
                nums.pb(0);
            }
            for (int i = 8; i >= 0; i--) {
                cout << nums[i];
            }
            cout << "\n";
            return;
        }
    }
    cout << "2\n";
}     
