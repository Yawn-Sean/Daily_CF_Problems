/*
由于至少有 2 个字符，所以是有可能无解的
看起来很 DP，考虑前 i 个字符至多能划分成多少个子串
dp[i] = dp[j - 1] + 1，s[i] == s[j] 且 j < i 且 j >= 1 且 dp[j - 1] 必须得合法
我们似乎可以维护每种字符出现的位置，这样 s[i] 找 s[j] 也好找，可以维护这里面这个东西的前缀最大
对于字符 ch，其假如在 i 位置出现过，则需要把 dp[i - 1] 存起来，并动态维护这个东西的前缀最大
还要记从哪里转移过来的，所以一个简单的实现方式是维护 26 个堆，堆中的元素是 (dp[i - 1], i)
初始化时，必须找到 s[1] 和某个 s[i] 第一次相等的位置，才是第一个合法的位置
*/

int n, dp[N], from[N];
string s;
vector<priority_queue<PII>> pq(27);

void meibao() {
    cin >> n >> s;
    s = " " + s;
    bool valid = false;
    int pos = -1;
    for (int i = 2; i <= n; i++) {
        if (s[i] == s[1]) {
            dp[i] = 1;
            valid = true;
            pos = i;
            break;
        }
    }

    if (!valid) {
        cout << "-1\n";
        return;
    }
    
    pq[s[1] - 'a'].push({0, 1});
    // i >= 3
    for (int i = pos + 1; i <= n; i++) {
        int ch = s[i] - 'a';
        if (pq[ch].size() == 0) {
            dp[i] = 0;
            if (dp[i - 1] > 0) {
                pq[ch].push({dp[i - 1], i});
            }
            from[i] = 0;
        } else {
            auto tp = pq[ch].top();
            dp[i] = tp.first + 1;
            from[i] = tp.second - 1;
            if (dp[i - 1] > 0) {
                pq[ch].push({dp[i - 1], i});
            }
        }
    }
    if (dp[n] == 0) {
        cout << "-1\n";
    } else {
        cout << dp[n] << "\n";
        int cur = n;
        vector<int> lens;
        while (cur > 0) {
            int last = from[cur];
            lens.push_back(cur - last);
            cur = last;
        }
        reverse(lens.begin(), lens.end());
        assert(lens.size() == dp[n]);
        for (auto len : lens) {
            cout << len << " ";
        }
    }
}   
