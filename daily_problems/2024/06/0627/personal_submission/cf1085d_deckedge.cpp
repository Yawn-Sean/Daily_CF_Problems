#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), s = red(), cnt = 0;
    ve<int> a(n);
    rep(i, 1, n) {
        int u = red(), v = red();
        a[--u]++, a[--v]++;
    }
    for (auto& x : a) {
        cnt += x == 1;
    }
    cout << fixed << setprecision(12) << 2.0 * s / cnt << '\n';
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
https://codeforces.com/problemset/problem/1085/D
*/