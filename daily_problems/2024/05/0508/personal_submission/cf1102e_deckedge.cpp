#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
using pi = pair<int, int>;

const int mod = 998244353;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), i;
    vector<int> a(n), b(n);
    map<int, int> mp;
    generate(all(a), red);

    for (i = n - 1; i >= 0; i--) {
        if (!mp.count(a[i])) {
            mp[a[i]] = i;
        }
        b[i] = mp[a[i]];
    }

    int res = 1, cur = -1;
    rep(i, 0, n - 1) {
        cur = max(cur, b[i]);
        if (cur == i) {
            res = res * 2 % mod;
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
https://codeforces.com/problemset/problem/1102/E
*/