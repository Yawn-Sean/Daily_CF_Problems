/*
s 是一个回文串，对 s 做切割，然后交换顺序重新拼接，得到一个新的回文串
ab|cbaabc|ba
ba|cbaabc|ab
ab|aca|ba
ba|aca|ab
事实上，找 s 的不相交的相等长度的前缀和后缀，二者只要不一样，就可以交换，交换之后就还是回文串，所以答案存在的话，至多是 2
1 次交换就是砍掉一个前缀，拼接到后面，什么时候可以这样呢？
这个前缀是 [0, i - 1]，则 [0, 2 * i - 1] 需要是回文的，[2 * i, n - 1] 需要是回文的，且新串和原串不一样
*/

struct MyHash {
    LL MOD, n, p[N], h[N], rh[N], P;

    // 正反的哈希值都求，方便处理回文串问题
    void init(string s, LL power, LL mod) {
        n = s.size();
        MOD = mod;
        P = power;
        p[0] = 1;
        h[0] = s[0];
        for (int i = 1; i < n; i++) {
            h[i] = h[i - 1] * P + s[i];
            h[i] %= MOD;
        }
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P % MOD;
        }
        rh[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rh[i] = rh[i + 1] * P + s[i];
            rh[i] %= MOD;
        }
    }
    
    // leetcode 上面有时候会重复用一个数据结构，所以需要提供一个清空方法
    void reset(int nn) {
        for (int i = 0; i < nn; i++) {
            p[i] = 0;
        }
        for (int i = 0; i < nn; i++) {
            h[i] = 0;
        }
        for (int i = 0; i < nn; i++) {
            rh[i] = 0;
        }
    }
    
    // 正着的字串的哈希值
    LL get(int l, int r) {
        if (l == 0) return h[r];
        return (((h[r] - h[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD);
    }

    // 反着的子串的哈希值
    LL rget(int l, int r) {
        if (r == n - 1) return rh[l];
        return (((rh[l] - rh[r + 1] * p[r - l + 1]) % MOD + MOD) % MOD);
    }
};

string s;
int n;
MyHash h;

void meibao() {
    cin >> s;
    n = s.size();
    h.init(s, P, MOD1);
    int res = -1;
    for (int i = 0; i < n / 2; i++) {
        if (h.get(0, i) != h.get(n - i - 1, n - 1)) {
            res = 2;
            break;
        }
    }
    if (res != 2) {
        cout << "Impossible\n";
        return;
    }

    // 答案为 1 的情况
    for (int i = 1; i <= n / 2; i++) {
        string t = s.substr(i) + s.substr(0, i);
        if (t != s && h.get(0, 2 * i - 1) == h.rget(0, 2 * i - 1)) {
            if (2 * i >= n || (h.get(2 * i, n - 1) == h.rget(2 * i, n - 1))) {
                res = 1;
            }
        }
    }
    cout << res << "\n";
}
