#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin() + 1, (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), fi = 0, se = 0, res = 1;
    vector<int> a(n + 1), b(n + 1);
    generate(all(a), red);
    rep(i, 1, n + 1) {
        if (a[i] > fi) {
            se = fi;
            fi = a[i];
            b[fi] = -1;
        } else if (a[i] > se) {
            se = a[i];
            b[fi]++;
        }
    }
    rep(i, 1, n + 1) {
        if (b[i] > b[res]) {
            res = i;
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
https://codeforces.com/problemset/problem/900/C
*/
