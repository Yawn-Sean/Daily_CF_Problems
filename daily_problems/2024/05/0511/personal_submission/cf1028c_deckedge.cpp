#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
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
    int n = red();
    vector<vector<int>> a(n, vector<int>(4));
    multiset<int> s[4];
    rep(i, 0, n) {
        rep(j, 0, 4) {
            a[i][j] = red();
            s[j].insert(a[i][j]);
        }
    }

    rep(i, 0, n) {
        rep(j, 0, 4) {
            s[j].erase(s[j].find(a[i][j]));
        }
        if (*s[0].rbegin() <= *s[2].begin() && *s[1].rbegin() <= *s[3].begin()) {
            cout << *s[0].rbegin() << ' ' << *s[1].rbegin() << '\n';
            break;
        }
        rep(j, 0, 4) {
            s[j].insert(a[i][j]);
        }
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
https://codeforces.com/problemset/problem/1028/C
*/