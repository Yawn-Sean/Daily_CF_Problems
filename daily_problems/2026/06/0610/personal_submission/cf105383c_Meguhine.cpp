#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include <local/dbg.h>
#else
    #define dbg(...) 42
#endif

using LL = long long;

// clang-format off
#define ai(x) using ai##x = array<int, x>;
ai(2); ai(3); ai(4); ai(5); ai(6); ai(7); ai(8); ai(9); ai(10); ai(26);
#undef ai
// clang-format on

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
template <class T>
inline bool updmx(T &x, const T &y) { return x < y ? x = y, 1 : 0; }
template <class T>
inline bool updmn(T &x, const T &y) { return y < x ? x = y, 1 : 0; }
template <class T>
inline void clr(T &x) { T().swap(x); }

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l, LL r) { return rng() % (r - l + 1) + l; }

template <typename T>
inline T __fen_add(const T x, const T y) { return x + y; }
template <typename T, auto op = __fen_add<T>, auto e = []() { return T(0); }> // T is int or LL
struct Fenwick {
    int n, LOG;
    vector<T> c;
    inline int lowbit(const int &x) {
        return x & (-x);
    }
    Fenwick() {}
    Fenwick(int n_) {
        init(n_);
    }
    void init(int n_) {
        c.assign(n = n_, e());
        LOG = bit_width((unsigned)n);
    }
    void add(int i, T x) {
        for (; i < n; i += lowbit(i)) c[i] = op(c[i], x);
    }
    T query(int i) {
        T res = e();
        for (; i; i -= lowbit(i)) res = op(res, c[i]);
        return res;
    }
    int kth(T k) { // min p that sum(1,p)>=k
        int ans = 0;
        T res = e();
        for (int i = LOG; ~i; --i) {
            int nxt = ans + (1 << i);
            if (nxt < n && op(res, c[nxt]) < k) {
                res = op(res, c[nxt]);
                ans = nxt;
            }
        }
        return ans + 1;
    }
};

int main() {
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n;
    cin >> n;
    Fenwick<int> fen_calc;
    auto calc = [&](const vector<int> &a) -> LL {
        fen_calc.init(n + 1);
        LL inv = 0;
        for (int i = n; i > 0; --i) {
            inv += fen_calc.query(a[i]);
            fen_calc.add(a[i], 1);
        }
        return inv;
    };
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        b[a[i]] = x;
        a[i] = i;
    }
    LL inv_a = 0, inv_b = calc(b);
    dbg(a | views::drop(1));
    dbg(b | views::drop(1));
    dbg(inv_b);
    if (inv_b & 1) {
        cout << "No";
        return 0;
    }
    Fenwick<int> fen(n + 1);
    for (int i = 1; i <= n; ++i) fen.add(i, 1);
    int pref = 0;
    for (int i = 1;; ++i) {
        const LL na = inv_a + (n - i);
        const LL nb = inv_b + (n - i) - fen.query(b[i] - 1) * 2;
        if (na > nb) break;
        fen.add(b[i], -1);
        inv_a = na, inv_b = nb;
        ++pref;
        if (na == nb) break;
    }
    dbg(pref, inv_a, inv_b);
    for (int i = pref + 1; inv_a != inv_b && i < n; ++i) {
        ++inv_a;
        if (b[i] < b[i + 1])
            ++inv_b;
        else
            --inv_b;
        swap(a[i], a[i + 1]);
        swap(b[i], b[i + 1]);
    }
    cout << "Yes\n";
    for (int i = pref + 1; i <= n; ++i) cout << a[i] << ' ';
    for (int i = pref; i > 0; --i) cout << a[i] << ' ';
    cout << '\n';
    for (int i = pref + 1; i <= n; ++i) cout << b[i] << ' ';
    for (int i = pref; i > 0; --i) cout << b[i] << ' ';
    cout << '\n';
#ifdef LOCAL
    vector<int> _a{0};
    _a.reserve(n + 1);
    for (int i = pref + 1; i <= n; ++i) _a.push_back(a[i]);
    for (int i = pref; i > 0; --i) _a.push_back(a[i]);
    vector<int> _b{0};
    _b.reserve(n + 1);
    for (int i = pref + 1; i <= n; ++i) _b.push_back(b[i]);
    for (int i = pref; i > 0; --i) _b.push_back(b[i]);
    dbg(calc(_a), calc(_b));
    assert(calc(_a) == calc(_b));
#endif
    return 0;
}

/*
超级精妙的一道题啊 !!!
我的构造过程是这样, 先把 a 变成 1~n
然后每次, 把当前剩余的部分, 选取一个最长的前缀进行翻转
使得翻转后, a 的逆序对个数 <= b 的逆序对个数
然后后续过程, 不考虑这部分前缀-1 的长度, 只观察剩余的部分
---
以上做法过不了, 会 TLE on test case 40.
问题在于, 当翻转某两个前缀, 改变的逆序对数量相同时, 必须保留靠前的位置
这会导致每个位置被访问不止一次, 时间复杂度是 O(n^2 logn)
---
还是老老实实模拟冒泡排序吧
*/
