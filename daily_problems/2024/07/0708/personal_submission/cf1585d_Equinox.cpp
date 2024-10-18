#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e9 + 7, P = 998244353;

template<typename T = int>
class FenWick {
private:
    int n;
    std::vector<T> tr;
public:
    FenWick(int _n) : n(_n), tr(_n + 1) 
    {}

    FenWick(int _n, std::vector<T> _init) : FenWick(_n) {
        init(_init);
    }

    void init(std::vector<T> _init) {
        for (int i = 1; i <= n; i ++ ) {
            tr[i] += _init[i - 1];
            tr[i + (i & -i)] += tr[i];
        }
    }

    void add(T x, T k) {
        for (; x <= n; x += x & -x) tr[x] += k;
    }

    void add(T l, T r, T k) {
        add(l, k), add(r + 1, -k);
    }

    T query(T x) const {
        if (x > n) return T();
        T res = 0;
        for (; x; x &= x - 1) res += tr[x];
        return res;
    }
};

/*
    一次轮换 <-> 两次交换 -> 逆序对奇偶不变
    若存在重复元素，ok
    

    若偶逆序，ok
    若奇逆序，not ok
*/

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<bool> vis(n + 1);
    bool f = false;


    for (int i = 0; i < n; i ++ ) {
        std::cin >> a[i];
        if (vis[a[i]]) f = true;
        vis[a[i]] = true;
    }

    if (f) {
        std::cout << "YES\n";
        return;
    }

    FenWick<int> tr(n);
    i64 s = 0;
    for (int x : a) 
        s += tr.query(n) - tr.query(x), tr.add(x, 1);
    
    if (s % 2 == 0) f = true;

    std::cout << (f ? "YES\n" : "NO\n");
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_ --)
        solve();
    return 0;
}