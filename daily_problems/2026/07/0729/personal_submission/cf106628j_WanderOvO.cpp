/*
考虑枚举某个串，要么是枚举 A 要么是枚举 C
如果是枚举 A，假设 A 是 s[1...i]
则大概要用 KMP 求一个 ne
我们需要找 ne[j] = i 的 j，则 j - i + 1 就是 C 的第一个位置
那么只需要判断 s[i + 1...j - i] 是不是 s[j - i + 1...n] 的后缀就好了
等下，我为什么不考虑枚举 B 呢？
因为 B 的开头结尾都不确定，不太好枚举吧
如果是枚举 C 呢？
那么我们关心 C 的最长的前缀，使得 C 的前缀 = S 的前缀且无重叠
这个事情可以二分做到
关于后缀，好像也可以二分呢
然后似乎就可以求方案数了
*/ 

const int N = 2e5 + 10;
const int P = 13331;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;

struct MyHash {
    LL h[N], p[N], mod;

    void init(string s, int n, int P, int _mod) {
        mod = _mod;
        for (int i = 0; i <= n; i++) {
            h[i] = 0;
            p[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            h[i] = P * h[i - 1] + s[i];
            h[i] %= mod;
        }

        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P % mod;
        }
    }

    LL get(int l, int r) {
        return ((h[r] - h[l - 1] * p[r - l + 1] % mod) % mod + mod) % mod;
    }
};

MyHash h1, h2;
string s;
int n;

LL calc_pre(int st) {
    int l = 1, r = min(n - st + 1, st - 2);
    if (l > r) {
        return 0;
    }

    auto check = [&] (int ans) {
        return (h1.get(1, ans) == h1.get(st, st + ans - 1));
    };

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if (check(r)) {
        return r;
    } else if (check(l)) {
        return l;
    }
    return -1;
}

LL calc_suf(int st) {
    // st - 1 - l <= n - st
    // l >= 2 * st - n - 1
    int l = max(2, 2 * st - n - 1), r = st - 1;
    if (l > r) {
        return 0;
    }

    auto check = [&] (int ans) {
        return (h1.get(ans, st - 1) == h1.get(n - (st - ans) + 1, n));
    };

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    if (check(l)) {
        return l;
    } else if (check(r)) {
        return r;
    }
    return -1;
}

void solve() {
    cin >> s;
    n = s.size();
    s = " " + s;
    h1.init(s, n, P, mod1);
    h2.init(s, n, P, mod2);

    LL res = 0;
    for (int i = n; i > 2; i--) {
        LL pos1 = calc_pre(i);
        LL pos2 = calc_suf(i);
        if (pos1 != -1 && pos2 != -1 && pos1 + 1 >= pos2) {
            res += pos1 - (pos2 - 1) + 1;
        }
    }
    cout << res << "\n";
}
