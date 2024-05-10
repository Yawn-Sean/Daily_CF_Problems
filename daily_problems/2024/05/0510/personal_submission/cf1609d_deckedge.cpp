#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

class dsu {
public:
    int n;
    vector<int> sz, p;
    dsu(int _n) : n(_n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(all(p), 0);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            sz[y] += sz[x];
            sz[x] = 0;
            return true;
        }
        return false;
    }
};

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), dd = red();
    dsu d(n);
    int cc = 1;
    rep(i, 0, dd) {
        int x = red(), y = red();
        x--, y--;
        if (!d.unite(x, y)) {
            cc += 1;
        }
        vector<int> b;
        rep(i, 0, n) {
            if (d.get(i) == i) {
                b.emplace_back(d.sz[i]);
            }
        }
        sort(rall(b));
        cout << accumulate(b.begin(), b.begin() + cc, 0) - 1 << '\n';
    }
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

/*
https://codeforces.com/problemset/problem/1609/D
*/