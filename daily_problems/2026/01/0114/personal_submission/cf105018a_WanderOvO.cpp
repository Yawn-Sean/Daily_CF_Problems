/*
s[1...j] 全部 flip 之后，是 s[i - j + 1...i]
我们维护一个 flip 后的串
相当于搞一个原串的 pre 和 flip 后的串的 suf 的 next 数组
011001
100110
如果 s[1...j] 和 s[i - j + 1...i] 可以
那么 s[1...j - 1] 和 s[i - j + 1...i - 1] 是否可以？
一定是可以的
假如 q[i] = k，那么 q[i + 1] 可能是多少呢？
q[i] = k，说明 s[1...k] = s[i - k + 1...i]
q[i + 1] 是看哪个最大的 j 满足 s[1...j] = t[i - j + 1...i]
现在已知有 s[1...k] = t[i - k + 1...i]
如果 s[k + 1] = t[i + 1]，则直接 q[i + 1] = q[i] + 1
否则参考使用 kmp 的方法
我们直接把 s 和 flip(s) 拼在一起做就好
*/

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string t;
    for (auto ch : s) {
        char c = '0' + ((ch - '0') ^ 1);
        t += c;
    }    
    s = s + " " + t;

    vector<int> kmp(2 * n + 1);
    int j = 0;
    for (int i = 1; i <= 2 * n; i++) {
        while (j && s[j] != s[i]) {
            j = kmp[j - 1];
        }
        if (s[j] == s[i]) {
            j++;
        }

        kmp[i] = j;
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        cout << kmp[i] << " ";
    }
    cout << "\n";
}
