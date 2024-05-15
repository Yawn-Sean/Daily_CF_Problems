/*
统计在 [1, n] 之间，且变换次数不超过 k 的数字个数
由于 n < 2^1000，所以 1 次操作就能把 n 降到 1000 以内
我们求出来 [1, 1000] 里面哪些数字是恰好 k 次能变成 1 的，这些直接统计到答案中即可
然后求 [1, 1000] 中哪些数字需要恰好 k - 1 次操作变成 1
对于恰好 k - 1 次的这些数字，我们枚举这些数字，设为 val
对每个 val，做数位 DP，求 [val + 1, n] 中有多少数字的二进制位 1 的个数为 val
*/

int T;
string s;
int k, op_cnt[N];
LL dp[N][N]; // dp[i][j]: 长度为 i 的 01 串，包含 j 个 1 的串的数量

LL calc(string &s, LL target) {
    vector<int> nums;
    for (auto ch : s) {
        nums.pb(ch - '0');
    }

    LL res = 0;
    int cnt = 0;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (cnt > target) {
            break;
        }
        int x = nums[i];
        if (x == 1) {
            res += dp[len - i - 1][target - cnt];
            cnt++;
        }
        if (i == len - 1) {
            if (cnt == target) {
                res++;
            }
        }
        res %= MOD1;
    }
    return res % MOD1;
}

void solve1() {
    cin >> s >> k;
    if (k == 0) {
        cout << "1" << endl;
        return;
    }
    op_cnt[1] = 0;
    for (int i = 2; i < N; i++) {
        int cnt = getcnt(i);
        op_cnt[i] = op_cnt[cnt] + 1;
    }
    if (s.size() <= 11) {
        int val = 0;
        for (auto ch : s) {
            val = 2 * val + ch - '0';
        }
        if (val <= 1000) {
            int res = 0;
            for (int i = 1; i <= val; i++) {
                if (op_cnt[i] == k) {
                    res++;
                }
            }
            cout << res << endl;
            return;
        }
    }

    LL res = 0;
    for (int i = 1; i <= 1000; i++) {
        if (op_cnt[i] == k - 1) {
            string t;
            int val = i;
            while (val > 0) {
                t += (char)((val % 2) + '0');
                val /= 2;
            }
            res += calc(s, i) - calc(t, i);
            res = (res % MOD1 + MOD1) % MOD1;
        }
    }
    cout << res << endl;
}                                                                                                                  