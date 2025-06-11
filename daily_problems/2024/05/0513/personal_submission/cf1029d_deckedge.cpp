#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), k = red();
    int64_t res = 0;
    vector<int> a(n), b = {1};
    generate(all(a), red);
    rep(i, 0, 10) {
        b.emplace_back((10ll * b.back()) % k);
    }
    vector c(10, vector<int>()), d(10, vector<int>());
    rep(j, 0, 10) {
        rep(i, 0, n) {
            c[j].emplace_back((1ll * b[j + 1] * a[i]) % k);
        }
    }
    rep(i, 0, 10) {
        d[i] = c[i];
    }
    rep(i, 0, 10) {
        sort(all(c[i]));
    }
    rep(i, 0, n) {
        int cur = k - (a[i] % k);
        if (cur == k) {
            cur = 0;
        }
        int len = to_string(a[i]).size();
        res += upper_bound(all(c[len - 1]), cur) - lower_bound(all(c[len - 1]), cur);
        if (d[len - 1][i] == cur) {
            res--;
        }
    }
    cout << res << '\n';
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
https://codeforces.com/contest/1029/problem/D
*/